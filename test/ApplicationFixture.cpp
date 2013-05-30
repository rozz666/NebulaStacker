#include "ApplicationFixture.hpp"
#include <NebulaStacker.hpp>

void ApplicationFixture::stack(Strings lightFrames, std::string output)
{
    filesToRemove.add(output);
    stacker.setLightFrames(lightFrames);
    stacker.stack(output);
}
