#include <Nebula/NebulaStackerFactory.hpp>
#include <Nebula/TiffImageReader.hpp>
#include <Nebula/TiffImageWriter.hpp>
#include <Nebula/FrameAveragerFactory.hpp>
#include <Nebula/makeWithDependencies.hpp>

namespace Nebula
{

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

}
