// IEaxManager backed by EalMan, a portable reimplementation of Creative's
// EAX Manager (EAXMan.dll).

// EalMan.h goes first: EaxMan.h defines its EMFLAG_* names as macros.
#include "EalMan.h"

#include <string.h>
#include <sstream>
#include <string>

#include "../OpenAL/al.h"
#include "EaxMan.h"

static_assert(sizeof(EAXREVERBPROPERTIES) == sizeof(EAXListenerProperties), "EAX reverb ABI mismatch");

namespace {

EMPoint ToEMPoint(const EMPOINT *point)
{
	EMPoint value;
	value.fX = point->fX;
	value.fY = point->fY;
	value.fZ = point->fZ;
	return value;
}

void ToEMPOINT(const EMPoint &value, EMPOINT *point)
{
	point->fX = value.fX;
	point->fY = value.fY;
	point->fZ = value.fZ;
}

class EalManager final : public IEaxManager
{
public:
	STDMETHOD(QueryInterface)(REFIID, LPVOID *object) { *object = NULL; return EM_INVALIDID; }
	STDMETHOD_(ULONG, AddRef)() { return 1; }
	STDMETHOD_(ULONG, Release)() { delete this; return 0; }

	STDMETHOD(LoadDataSet)(char *data, DWORD flags)
	{
		if (!(flags & EMFLAG_LOADFROMMEMORY))
			return manager.LoadDataSet(data, flags);

		// Like EAXMan.dll, take the size from the RIFF header; callers check
		// that it fits their buffer.
		const unsigned char *riff = (const unsigned char *)data;
		const size_t size = 8 + (riff[4] | (riff[5] << 8) | (riff[6] << 16) | ((uint32_t)riff[7] << 24));
		std::istringstream stream(std::string(data, size), std::ios::binary);
		return manager.LoadDataSetFromMemory(stream);
	}

	STDMETHOD(FreeDataSet)(DWORD flags) { return manager.FreeDataSet(flags); }

	STDMETHOD(GetSourceID)(char *name, long *id)
	{
		int32_t value = 0;
		const HRESULT result = manager.GetSourceID(name, value);
		*id = value;
		return result;
	}

	STDMETHOD(GetSourceNumInstances)(long id, long *count)
	{
		int32_t value = 0;
		const HRESULT result = manager.GetSourceNumInstances(id, value);
		*count = value;
		return result;
	}

	STDMETHOD(GetSourceInstancePos)(long id, long instance, LPEMPOINT position)
	{
		EMPoint value;
		const HRESULT result = manager.GetSourceInstancePos(id, instance, value);
		ToEMPOINT(value, position);
		return result;
	}

	STDMETHOD(GetEnvironmentAttributes)(long id, LPEAXREVERBPROPERTIES attributes)
	{
		EAXListenerProperties value;
		const HRESULT result = manager.GetEnvironmentAttributes(id, value);
		if (result == EM_OK)
			memcpy(attributes, &value, sizeof(value));
		return result;
	}

	STDMETHOD(GetListenerDynamicAttributes)(long geometryID, LPEMPOINT position, long *envID, DWORD flags)
	{
		int32_t value = 0;
		const HRESULT result = manager.GetListenerDynamicAttributes(geometryID, ToEMPoint(position), value, flags);
		*envID = value;
		return result;
	}

	STDMETHOD(GetSourceDynamicAttributes)(long geometryID, LPEMPOINT position, int32_t *obstruction,
		float *obstructionLF, int32_t *occlusion, float *occlusionLF, float *occlusionRoom,
		LPEMPOINT virtualPosition, DWORD flags)
	{
		EMPoint value;
		const HRESULT result = manager.GetSourceDynamicAttributes(geometryID, ToEMPoint(position),
			*obstruction, *obstructionLF, *occlusion, *occlusionLF, *occlusionRoom, value, flags);
		ToEMPOINT(value, virtualPosition);
		return result;
	}

	STDMETHOD(GetEnvironmentName)(long id, char *name, long nameSize)
	{
		if (nameSize <= 0)
			return EM_INVALIDID;
		std::string value;
		const HRESULT result = manager.GetEnvironmentName(id, value, nameSize);
		const size_t length = result != EM_OK ? 0
			: value.size() < (size_t)nameSize ? value.size() : (size_t)nameSize - 1;
		memcpy(name, value.data(), length);
		name[length] = '\0';
		return result;
	}

	// Jedi Academy never calls these.
	STDMETHOD(GetDataSetSize)(unsigned long *, DWORD) { return EM_INVALIDID; }
	STDMETHOD(GetListenerAttributes)(LPLISTENERATTRIBUTES) { return EM_INVALIDID; }
	STDMETHOD(GetSourceAttributes)(long, LPSOURCEATTRIBUTES) { return EM_INVALIDID; }
	STDMETHOD(GetEnvironmentID)(char *, long *) { return EM_INVALIDID; }
	STDMETHOD(GetMaterialID)(char *, long *) { return EM_INVALIDID; }
	STDMETHOD(GetMaterialAttributes)(long, LPMATERIALATTRIBUTES) { return EM_INVALIDID; }
	STDMETHOD(GetGeometrySetID)(char *, long *) { return EM_INVALIDID; }

private:
	EalMan manager;
};

}

HRESULT __stdcall EaxManagerCreate(LPEAXMANAGER *manager)
{
	*manager = new EalManager;
	return EM_OK;
}
