#include "ApplicationFixture.hpp"
#include <NebulaStacker.hpp>
#include <NebulaStackerFactory.hpp>

ApplicationFixture::ApplicationFixture()
{
    stacker = NebulaStackerFactory().createNebulaStacker();
}

void ApplicationFixture::stack(Strings lightFrames, std::string output)
{
    filesToRemove.add(output);
    stacker->setLightFrames(lightFrames);
    stacker->stack(output);
}
