#include "EalMan_DataTypes.h"
#include "Chunk.h"

int32_t Chunk::read(
        std::istream&   file
        )
{
    std::array<char, 8> header{};
    if (!file.read(header.data(), header.size()))
    { return toInt(EalError::FileInvalid); }

    fourCC = static_cast<FourCC>(FourCCTools::fromBytes(&header[0]));
    length = FourCCTools::fromBytes(&header[4]);

    return toInt(EalError::OK);
}
