#pragma once

#include <string>
#include <vector>
#include <array>

#include "EalMan_DataTypes.h"

class EalData
{
public:
    // Global Diffraction Model
    EAXDiffractionModel gdfm{};

    // Default attributes
    ListenerAttributes    defListener{};
    EAXListenerProperties defEnvironment{};
    SourceAttributes      defSource{};
    MaterialAttributes    defObstacle{};
    //std::array<char, 260> defFile{}; // optional file name only useful for EAGLE editor
    //std::array<char, 260> defExep{}; // optional file name only useful for EAGLE editor
    //std::array<char, 260> defCmds{}; // optional file name only useful for EAGLE editor

    // Parsed datasets
    uint32_t nrEnvironments{};
    uint32_t nrSources{};
    uint32_t nrObstacles{};
    std::vector<EAXListenerProperties> environments{};
    std::vector<SourceAttributes>      sources{};
    std::vector<MaterialAttributes>    obstacles{};

    std::vector<std::string> srcNames{};
    std::vector<std::string> obsNames{};
    std::vector<std::string> envNames{};
    std::vector<std::string> geoNames{};
    //std::vector<std::string> srcFileNames; // optional file names only useful for EAGLE editor
    //std::vector<std::string> geomFileNames; // optional file names only useful for EAGLE editor

    // GEMA Chunk info
    uint32_t gemaNrSrcIDs{};
    uint32_t gemaNrEnvIDs{};
    uint32_t gemaStartID{};
    uint32_t gemaNrInnerNodes{};
    uint32_t gemaNrOuterNodes{};
    uint32_t gemaNrDiffBox{};
    std::vector<int32_t>        gemaEnvIDs{};
    std::vector<int32_t>        gemaSrcIDs{};
    std::vector<EMPoint>        gemaSources{};
    std::vector<int32_t>        gemaDiffraction{};
    std::vector<int32_t>        gemaEnvironmentMatrix{};
    std::vector<SplitNode>      gemaBSPinnerNodes{};
    std::vector<Zone>           gemaBSPouterNodes{};
    std::vector<DiffractionBox> gemaDiffBox{};

public:
    EalData() = default;
    ~EalData() = default;
};
