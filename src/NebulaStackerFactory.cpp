#include "NebulaStackerFactory.hpp"
#include "TiffImageReader.hpp"
#include "TiffImageWriter.hpp"
#include <boost/make_shared.hpp>

NebulaStackerPtr NebulaStackerFactory::createNebulaStacker()
{
    struct StackerWithDependencies
    {
        TiffImageReader imageReader;
        TiffImageWriter imageWriter;
        NebulaStacker stacker;
        StackerWithDependencies()
            : stacker(imageReader, imageWriter) { }
    };
    auto withDeps = boost::make_shared<StackerWithDependencies>();
    return NebulaStackerPtr(withDeps, &withDeps->stacker);
}


