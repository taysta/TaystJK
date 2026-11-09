#pragma once

#include <cstdint>
#include <array>
#include <fstream>

#include "FourCC.h"

class Chunk
{
public:
    FourCC   fourCC{}; // defaults to 0 which is not inside the FourCC enum so the later comparisons don't equate a misread FourCC as legit
    uint32_t length{};

public:
    Chunk() = default;

    // Liest den Chunk-Header (8 Bytes)
    int32_t read(
            std::istream&   file
            );

    // Prüft, ob der Chunk einem bestimmten FourCC entspricht
    bool Equals(
            FourCC   other
            ) const noexcept
    {
        return fourCC == other;
    }
};
