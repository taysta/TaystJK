#pragma once
#include <bitset>
#include <cstdint>
#include <memory>
#include "EalMan_DataTypes.h"
#include "EalData.h"
#include "FourCC.h"

class EalMan
{
private:
    /* organized data read from an .eal file */
    std::unique_ptr<EalData>   m_data{};
    /* buffered listener position */
    EMPoint                    m_listenerPosition{};
    /* buffered environment the listener position is in */
    int32_t                    m_listenerEnvIDIndex{};

    /* file size in bytes */
    size_t   m_fileSize{};

    int32_t getIndexIDfromBSP(
        int32_t&        idx,
        const EMPoint   pos
    ) const;

    int32_t computeDiffraction(
        const EMPoint&   listener,
        const EMPoint&   source,
        const EMPoint&   intersection,
        const uint32_t   boxSide,
        const EMPoint&   boxMin,
        const EMPoint&   boxMax
        ) const;

    template <typename T>
    int32_t ReadArrayData(
            std::istream&     file,
            uint32_t          count,
            std::vector<T>&   dest,
            uint32_t&         bytesRead
            );

    int32_t EalGlobals(
            std::istream&   file,
            const FourCC    fourcc,
            uint32_t&       bytesRead
            );

    int32_t EalList(
            std::istream&                                           file,
            std::bitset<static_cast<uint32_t>(FourCCreq::COUNT)>&   reqFourCC,
            uint32_t&                                               bytesRead
            );

    int32_t EalEnvironmentAttributes(
            std::istream&                                           file,
            std::bitset<static_cast<uint32_t>(FourCCreq::COUNT)>&   reqFourCC,
            uint32_t&                                               bytesRead
            );

    int32_t EalObstacleAttributes(
            std::istream&   file,
            uint32_t&       bytesRead
            );

    int32_t EalSourceAttributes(
            std::istream&   file,
            uint32_t&       bytesRead
            );

    int32_t EalGeometryAttributes(
            std::istream&                                           file,
            std::bitset<static_cast<uint32_t>(FourCCreq::COUNT)>&   reqFourCC,
            uint32_t&                                               bytesRead
            );

    int32_t ReadNumsChunk(
            std::istream&   file,
            uint32_t&       count,
            uint32_t&       bytesRead
            );

    int32_t ReadNamsChunk(
            std::istream&               file,
            uint32_t                    count,
            std::vector<std::string>&   dest,
            uint32_t&                   bytesRead
            );
    /*
    int32_t ReadFilsChunk(
            std::istream&               file,
            uint32_t                    count,
            std::vector<std::string>&   dest,
            uint32_t&                   bytesRead
            );
    */
    template <typename T>
    int32_t ReadDataChunk(
            std::istream&     file,
            uint32_t          count,
            const FourCC      fourCC,
            std::vector<T>&   dest,
            uint32_t&         bytesRead
            );

    int32_t ReadGemaChunk(
            std::istream&   file,
            uint32_t&       bytesRead
            );

    int32_t GetID(
            const std::string&          name,
            int32_t&                    id,
            std::vector<std::string>&   dataset
            ) const;

    template <typename T>
    int32_t GetAttributes(
            const int32_t     id,
            const int32_t     length,
            T&                attributes,
            std::vector<T>&   dataset
            ) const;

    int32_t ParseDataSet(
            std::istream&   file
            );

    inline bool isGDFMdataPlausible() const;
    inline bool isDEFLdataPlausible() const;
    inline bool isDEFEdataPlausible() const;
    inline bool isDEFSdataPlausible() const;
    inline bool isDEFMdataPlausible() const;
    bool isLISPdataPlausible() const;
    bool isMATAdataPlausible() const;
    bool isSRCAdataPlausible() const;
    bool isGEMAdataPlausible() const;

public:
    EalMan();
    ~EalMan();

    /**
     * @brief returns the size in bytes of the currently loaded eal file
     *
     * @param sizeDataSet [out] Size in bytes of currently loaded dataset.
     * @param flags [in] Flags, reserved for future use.
     * @return EM_OK
     */
    int32_t GetDataSetSize(
            uint32_t&        sizeDataSet,
            const uint32_t   flags
            ) const;

    /**
     * @brief method loads an eal file into EalManager and sets it up for usage
     *
     * @param filename [in] Filename of eal to load
     * @param flags [in] Flags to use while getting attributes (currently unused)
     * @return EM_OK, EM_FILENOTFOUND, EM_FILEINVALID, EM_VERSIONINVALID
     */
    int32_t LoadDataSet(
            const std::string&   filename,
            const uint32_t       flags
            );

    /**
     * @brief method loads an eal from memory into EalManager and sets it up for usage
     *
     * @param file [in] memory stream of eal to load
     * @return EM_OK, EM_FILENOTFOUND, EM_FILEINVALID, EM_VERSIONINVALID
     */
    int32_t LoadDataSetFromMemory(
            std::istream&   file
            );

    /**
     * @brief unloads the currently loaded eal dataset
     *
     * @param flags [in] Flags (currently unused)
     * @return EM_OK
     */
    int32_t FreeDataSet(
            const uint32_t   flags
            );

    /**
     * @brief gets the listener attributes from the loaded eal dataset
     *
     * @param lstAttributes [out] Listener attribute structure, use this structure to set DirectSound3D Listener properties
     * @return EM_OK
     */
    int32_t GetListenerAttributes(
            ListenerAttributes&   lstAttributes
            ) const;

    /**
     * @brief returns the ID for a source given its name
     *
     * @param srcName [in] name of source to get ID for
     * @param srcID [out] ID to use for source
     * @return EM_OK, EM_IDNOTFOUND
     */
    int32_t GetSourceID(
            const std::string&   srcName,
            int32_t&             srcID
            ) const;

    /**
     * @brief gets the attributes for a source given its ID
     *
     * @param srcID [in] ID to use for source
     * @param srcAttributes [out] Source attribute structure; Use this structure to set DirectSound3D Buffer properties
     * @return EM_OK, EM_INVALIDID
     */
    int32_t GetSourceAttributes(
            const int32_t       srcID,
            SourceAttributes&   srcAttributes
            ) const;

    /**
     * @brief gets the number of instances for a source ID
     *
     * @param srcID [in] ID to use for source
     * @param srcInstances [out] Number of instances of the source placed in this geometry set
     * @return EM_OK, EM_INVALIDID
     */
    int32_t GetSourceNumInstances(
            const int32_t   srcID,
            int32_t&        srcInstances
            ) const;

    /**
     * @brief gets the 3D position of an instance for a source ID
     *
     * @param srcID [in] ID to use for source
     * @param srcInstance [in] Instance to use for source, zero-based
     * @param posInstance [out] 3D position of instance (srcID) of source (srcInstance)
     * @return EM_OK, EM_INVALIDID, EM_INSTANCENOTFOUND
     */
    int32_t GetSourceInstancePos(
            const int32_t   srcID,
            const int32_t   srcInstance,
            EMPoint&        posInstance
            ) const;

    /**
     * @brief returns the ID for an environment given its name
     *
     * @param envName [in] name of environment to get ID for
     * @param envID [out] ID to use for environment
     * @return EM_OK, EM_IDNOTFOUND
     */
    int32_t GetEnvironmentID(
            const std::string&   envName,
            int32_t&             envID
            ) const;

    /**
     * @brief gets the attributes for an environment given its ID
     *
     * @param envID [in] ID to use for environment
     * @param envAttributes [out] Environment attribute structure; Use this structure to set DirectSound3D EAXListener properties
     * @return EM_OK, EM_INVALIDID
     */
    int32_t GetEnvironmentAttributes(
            const int32_t            envID,
            EAXListenerProperties&   envAttributes
            ) const;

    /**
     * @brief returns the ID for a material given its name
     *
     * @param matName [in] name of material to get ID for
     * @param matID [out] ID to use for material
     * @return EM_OK, EM_IDNOTFOUND
     */
    int32_t GetMaterialID(
            const std::string&   matName,
            int32_t&             matID
            ) const;

    /**
     * @brief gets the attributes for a material given its ID
     *
     * @param matID [in] ID to use for material
     * @param matAttributes [out] Material attribute structure; Use this structure to set DirectSound3D EAXBuffer properties
     * @return EM_OK, EM_INVALIDID
     */
    int32_t GetMaterialAttributes(
            const int32_t         matID,
            MaterialAttributes&   matAttributes
            ) const;

    /**
     * @brief returns the ID for a geometry set given its name, because a single eal dataset can contain multiple geometry sets
     *
     * @param geomName [in] name of geometry set to get ID for
     * @param geomID [out] ID to use for geometry set
     * @return EM_OK, EM_IDNOTFOUND
     */
    int32_t GetGeometrySetID(
            const std::string&   geomName,
            int32_t&             geomID
            ) const;

    /**
     * @brief returns the ID for the environment in which the listener is currently located
     *
     * @param geomID [in] ID of geometry set to use, if only one geometry set is used, specify zero
     * @param lstPos [in] Current position of 3D listener
     * @param envID [out] ID to use for current environment
     * @param flags [in] Flags to use while getting attributes - EMFLAG_LOCKPOSITION saves the lstPos for subsequent use in GetSourceDynamicAttributes()
     * @return EM_OK, EM_IDNOTFOUND
     */
    int32_t GetListenerDynamicAttributes(
            const int32_t    geomID,
            const EMPoint&   lstPos,
            int32_t&         envID,
            const uint32_t   flags
            );

    /**
     * @brief returns the attributes that change dynamically for a source, given a geometry set and its position
     *
     * @param geomID [in] ID of geometry set to use, if only one geometry set is used, specify zero
     * @param srcPos [in] Current position of 3D sound source
     * @param srcObstruction [out] Source obstruction attribute; Use this value to set DirectSound3D Buffer properties
     * @param srcObstructionLF [out] Source obstruction lf ratio attribute; Use this value to set DirectSound3D Buffer properties
     * @param srcOcclusion [out] Source occlusion attribute; Use this value to set DirectSound3D Buffer properties
     * @param srcOcclusionLF [out] Source occlusion lf ratio attribute; Use this value to set DirectSound3D Buffer properties
     * @param srcOcclusionRM [out] Source occlusion room ratio attribute; Use this value to set DirectSound3D Buffer properties
     * @param virtPos [out] Virtual position to use for positioning sound (currently not implemented)
     * @param flags [in] Flags (currently unused)
     * @return EM_OK, EM_IDNOTFOUND
     */
    int32_t GetSourceDynamicAttributes(
            const int32_t    geomID,
            const EMPoint&   srcPos,
            int32_t&         srcObstruction,
            float&           srcObstructionLF,
            int32_t&         srcOcclusion,
            float&           srcOcclusionLF,
            float&           srcOcclusionRM,
            EMPoint&         virtPos,
            const uint32_t   flags
            );

#if EAXMANVERSION == 3
    /**
     * @brief gets the environment name for a source given its ID
     *
     * @param srcID [in] environment ID, whose name is to be searched for
     * @param envName [out] environment name
     * @param maxNameSize [in] maximum name size (currently unused)
     * @return EM_OK, EM_INVALIDID
     */
    int32_t GetEnvironmentName(
            const int32_t    envID,
            std::string&     envName,
            const uint32_t   maxNameSize
            ) const;
#endif
};
