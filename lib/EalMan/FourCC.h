#pragma once

#include <cstdint>
#include <string>
#include <array>

enum class FourCC : uint32_t
{
    RIFF = 0x46464952, // "RIFF"
    EAL  = 0x206C6165, // "eal "

    // Globals
    MAJV = 0x766A616D, // "majv"
    MINV = 0x766E696D, // "minv"
    EXEP = 0x70657865, // "exep"
    CMDS = 0x73646D63, // "cmds"
    GDFM = 0x6D666467, // "gdfm"
    LISA = 0x6173696C, // "lisa"
    DENV = 0x766E6564, // "denv"
    DSRC = 0x63727364, // "dsrc"
    DFIL = 0x6C696664, // "dfil"
    DMAT = 0x74616D64, // "dmat"

    // LIST subchunks
    LIST = 0x5453494C, // "LIST"
    ENVP = 0x70766E65, // "envp"
    MATP = 0x7074616D, // "matp"
    SRCP = 0x70637273, // "srcp"
    GEMP = 0x706D6567, // "gemp"

    // Data chunks
    NUM  = 0x206D756E, // "num "
    NAMS = 0x736D616E, // "nams"
    FILS = 0x736C6966, // "fils"
    LISP = 0x7073696C, // "lisp"
    MATA = 0x6174616D, // "mata"
    SRCA = 0x61637273, // "srca"
    GEMA = 0x616D6567  // "gema"
};

// which FourCCs are required to be parsable
enum class FourCCreq : uint32_t
{
    GDFM,
    LISA,
    DENV,
    DSRC,
    DMAT,

    // envp subchunks
    ENVP_NAMS,
    ENVP_LISP,

    // gemp subchunks
    GEMP_NAMS,
    GEMP_GEMA,

    COUNT
};

struct FourCCTools
{
    static constexpr uint32_t fromBytes(const char* p)
    {
        return
            (uint32_t(static_cast<uint8_t>(p[0]))      ) |
            (uint32_t(static_cast<uint8_t>(p[1])) <<  8) |
            (uint32_t(static_cast<uint8_t>(p[2])) << 16) |
            (uint32_t(static_cast<uint8_t>(p[3])) << 24);
    }

    static FourCC fromString(const std::string& s)
    {
        return static_cast<FourCC>(fromBytes(s.data()));
    }
};
