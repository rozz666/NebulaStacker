#include <Nebula/StackerFactory.hpp>
#include <Nebula/TiffImageReader.hpp>
#include <Nebula/TiffImageWriter.hpp>
#include <Nebula/FrameAveragerFactory.hpp>
#include <Nebula/makeWithDependencies.hpp>

namespace Nebula
{

StackerPtr StackerFactory::createStacker()
{
    struct Complete
    {
        TiffImageReader imageReader;
        TiffImageWriter imageWriter;
        FrameAveragerFactory frameCombinerFactory;
        Stacker stacker{imageReader, imageWriter, frameCombinerFactory};
    };
    return makeWithDependencies(&Complete::stacker);
}

}
