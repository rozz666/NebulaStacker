#include <Nebula/ApplicationFixture.hpp>
#include <Nebula/NebulaStackerFactory.hpp>

namespace Nebula
{

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

}
