#include "NebulaStackerFactory.hpp"
#include "TiffImageReader.hpp"
#include <boost/make_shared.hpp>

NebulaStackerPtr NebulaStackerFactory::createNebulaStacker()
{
    struct StackerWithDependencies
    {
        TiffImageReader imageReader;
        NebulaStacker stacker;
        StackerWithDependencies()
            : stacker(imageReader) { }
    };
    auto withDeps = boost::make_shared<StackerWithDependencies>();
    return NebulaStackerPtr(withDeps, &withDeps->stacker);
}


