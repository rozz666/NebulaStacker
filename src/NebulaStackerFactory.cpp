#include "NebulaStackerFactory.hpp"
#include "TiffImageReader.hpp"
#include "TiffImageWriter.hpp"
#include "FrameAveragerFactory.hpp"
#include "makeWithDependencies.hpp"

NebulaStackerPtr NebulaStackerFactory::createNebulaStacker()
{
    struct Complete
    {
        TiffImageReader imageReader;
        TiffImageWriter imageWriter;
        FrameAveragerFactory frameCombinerFactory;
        NebulaStacker stacker{imageReader, imageWriter, frameCombinerFactory};
    };
    return makeWithDependencies(&Complete::stacker);
}


