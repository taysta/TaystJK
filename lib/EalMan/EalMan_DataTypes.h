#pragma once
#include <cstdint>

struct EMPoint
{
    float fX;
    float fY;
    float fZ;
};

// include the structs of eax.h
struct EAXBufferProperties
{
    int32_t  lDirect;                 // direct path level
    int32_t  lDirectHF;               // direct path level at high frequencies
    int32_t  lRoom;                   // room effect level
    int32_t  lRoomHF;                 // room effect level at high frequencies
    float    flRoomRolloffFactor;     // like DS3D flRolloffFactor but for room effect
    int32_t  lObstruction;            // main obstruction control (attenuation at high frequencies)
    float    flObstructionLFRatio;    // obstruction low-frequency level re. main control
    int32_t  lOcclusion;              // main occlusion control (attenuation at high frequencies)
    float    flOcclusionLFRatio;      // occlusion low-frequency level re. main control
    float    flOcclusionRoomRatio;    // occlusion room effect level re. main control
    int32_t  lOutsideVolumeHF;        // outside sound cone level at high frequencies
    float    flAirAbsorptionFactor;   // multiplies DSPROPERTY_EAXLISTENER_AIRABSORPTIONHF
    uint32_t dwFlags;                 // modifies the behavior of properties
};

struct EAXSourceProperties
{
    int32_t  lDirect;                 // direct path level (at low and mid frequencies)
    int32_t  lDirectHF;               // relative direct path level at high frequencies
    int32_t  lRoom;                   // room effect level (at low and mid frequencies)
    int32_t  lRoomHF;                 // relative room effect level at high frequencies
    int32_t  lObstruction;            // main obstruction control (attenuation at high frequencies)
    float    flObstructionLFRatio;    // obstruction low-frequency level re. main control
    int32_t  lOcclusion;              // main occlusion control (attenuation at high frequencies)
    float    flOcclusionLFRatio;      // occlusion low-frequency level re. main control
    float    flOcclusionRoomRatio;    // relative occlusion control for room effect
    float    flOcclusionDirectRatio;  // relative occlusion control for direct path
    int32_t  lExclusion;              // main exlusion control (attenuation at high frequencies)
    float    flExclusionLFRatio;      // exclusion low-frequency level re. main control
    int32_t  lOutsideVolumeHF;        // outside sound cone level at high frequencies
    float    flDopplerFactor;         // like DS3D flDopplerFactor but per source
    float    flRolloffFactor;         // like DS3D flRolloffFactor but per source
    float    flRoomRolloffFactor;     // like DS3D flRolloffFactor but for room effect
    float    flAirAbsorptionFactor;   // multiplies EAXREVERB_AIRABSORPTIONHF
    uint32_t dwFlags;                 // modifies the behavior of properties
};

enum class EalBufferProperty
        : uint32_t
{
    None,
    AllParameters,
    Direct,
    DirectHF,
    Room,
    RoomHF,
    RoomRolloffFactor,
    Obstruction,
    ObstructionLFRatio,
    Occlusion,
    OcclusionLFRatio,
    OcclusionRoomRatio,
    OutsideVolumeHF,
    AirAbsorptionFactor,
    Flags
};

struct EAXListenerProperties
{
#if EAXMANVERSION == 3
    uint32_t ulEnvironment;            // sets all reverb properties
    float    flEnvironmentSize;        // environment size in meters
    float    flEnvironmentDiffusion;   // environment diffusion
    int32_t  lRoom;                    // room effect level (at mid frequencies)
    int32_t  lRoomHF;                  // relative room effect level at high frequencies
    int32_t  lRoomLF;                  // relative room effect level at low frequencies
    float    flDecayTime;              // reverberation decay time at mid frequencies
    float    flDecayHFRatio;           // high-frequency to mid-frequency decay time ratio
    float    flDecayLFRatio;           // low-frequency to mid-frequency decay time ratio
    int32_t  lReflections;             // early reflections level relative to room effect
    float    flReflectionsDelay;       // initial reflection delay time
    EMPoint  vReflectionsPan;          // early reflections panning vector
    int32_t  lReverb;                  // late reverberation level relative to room effect
    float    flReverbDelay;            // late reverberation delay time relative to initial reflection
    EMPoint  vReverbPan;               // late reverberation panning vector
    float    flEchoTime;               // echo time
    float    flEchoDepth;              // echo depth
    float    flModulationTime;         // modulation time
    float    flModulationDepth;        // modulation depth
    float    flAirAbsorptionHF;        // change in level per meter at high frequencies
    float    flHFReference;            // reference high frequency
    float    flLFReference;            // reference low frequency
    float    flRoomRolloffFactor;      // like DS3D flRolloffFactor but for room effect
    uint32_t ulFlags;                  // modifies the behavior of properties
#else
    int32_t  lRoom;                    // room effect level at low frequencies
    int32_t  lRoomHF;                  // room effect high-frequency level re. low frequency level
    float    flRoomRolloffFactor;      // like DS3D flRolloffFactor but for room effect
    float    flDecayTime;              // reverberation decay time at low frequencies
    float    flDecayHFRatio;           // high-frequency to low-frequency decay time ratio
    int32_t  lReflections;             // early reflections level relative to room effect
    float    flReflectionsDelay;       // initial reflection delay time
    int32_t  lReverb;                  // late reverberation level relative to room effect
    float    flReverbDelay;            // late reverberation delay time relative to initial reflection
    uint32_t dwEnvironment;            // sets all listener properties
    float    flEnvironmentSize;        // environment size in meters
    float    flEnvironmentDiffusion;   // environment diffusion
    float    flAirAbsorptionHF;        // change in level per meter at 5 kHz
    uint32_t dwFlags;                  // modifies the behavior of properties
#endif
};

enum class DSPPropertyEAXListenerProperty
{
    DSPPropertyEAXListenerNone,
    DSPPropertyEAXListenerAllParameters,
    DSPPropertyEAXListenerRoom,
    DSPPropertyEAXListenerRoomHF,
    DSPPropertyEAXListenerRoomRolloffFactor,
    DSPPropertyEAXListenerDacayTime,
    DSPPropertyEAXListenerDecayHFRatio,
    DSPPropertyEAXListenerReflections,
    DSPPropertyEAXListenerReflectionsDelay,
    DSPPropertyEAXListenerReverb,
    DSPPropertyEAXListenerReverbDelay,
    DSPPropertyEAXListenerEnvironment,
    DSPPropertyEAXListenerEnvironmentSize,
    DSPPropertyEAXListenerEnvironmentDiffusion,
    DSPPropertyEAXListenerAirAbsorptionHF,
    DSPPropertyEAXListenerFlags
};

enum class EalEnvironment
        : uint32_t
{
    Generic,
    PaddedCell,
    Room,
    Bathroom,
    LivingRoom,
    StoneRoom,
    Auditorium,
    ConcertHall,
    Cave,
    Arena,
    Hangar,
    CarpetedHallway,
    Hallway,
    StoneCorridor,
    Alley,
    Forest,
    City,
    Mountains,
    Quarry,
    Plain,
    ParkingLot,
    SewerPipe,
    Underwater,
    Drugged,
    Dizzy,
    Psychotic
};

// include the structs of EaxMan.h
enum class EalError
        : int32_t
{
    OK =               0,
    InvalidId =        static_cast<int32_t>(0x80040001),
    IdNotFound =       static_cast<int32_t>(0x80040002),
    FileNotFound =     static_cast<int32_t>(0x80040003),
    FileInvalid =      static_cast<int32_t>(0x80040004),
    VersionInvalid =   static_cast<int32_t>(0x80040005),
    InstanceNotFound = static_cast<int32_t>(0x80040006)
};

inline static int32_t toInt(EalError e)
{
    return static_cast<int32_t>(e);
}

constexpr uint32_t EMFLAG_IDNONE         = static_cast<uint32_t>(-2);
constexpr uint32_t EMFLAG_IDDEFAULT      = static_cast<uint32_t>(-1);
constexpr uint32_t EMFLAG_LOCKPOSITION   = 1;
constexpr uint32_t EMFLAG_LOADFROMMEMORY = 2;
constexpr uint32_t EMFLAG_NODIFFRACTION  = 4;

constexpr uint32_t EMMATERIAL_OBSTRUCTS  = 1;
constexpr uint32_t EMMATERIAL_OCCLUDES   = 3;

struct ListenerAttributes
{
    float fDistanceFactor;
    float fRolloffFactor;
    float fDopplerFactor;
};

struct SourceAttributes
{
#if EAXMANVERSION == 3
    EAXSourceProperties eaxAttributes;
#else
    EAXBufferProperties eaxAttributes;
#endif
    uint32_t ulInsideConeAngle;
    uint32_t ulOutsideConeAngle;
    int32_t  lConeOutsideVolume;
    float    fConeXdir;
    float    fConeYdir;
    float    fConeZdir;
    float    fMinDistance;
    float    fMaxDistance;
    int32_t  lDupCount;
    int32_t  lPriority;
};

struct MaterialAttributes
{
    int32_t  lLevel;
    float    fLFRatio;
    float    fRoomRatio;
    uint32_t dwFlags;
};

struct DiffractionBox
{
    int32_t lSubspaceID;
    EMPoint empMin;
    EMPoint empMax;
};

// neither eax.h nor EaxMan.h define a struct for the global diffraction model  stored in an .eal, so here it is:
struct EAXDiffractionModel
{
    int32_t MaxAttenuation;
    float   LFRatio;
    int32_t AngleMaxAttenuation;   // EAGLE clips value into range 0 .. 90, so it cannot be derived with certainty if field is signed or unsigned
};

struct SplitNode
{
    EMPoint  base;
    EMPoint  normal;
    uint32_t childFront;
    uint32_t childBack;
    uint32_t notUsedA;
    uint32_t notUsedB;
    int32_t  notUsedC;
};

struct Zone
{
    int32_t notUsed;
    int32_t indexEnvID;
};
