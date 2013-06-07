#include <Nebula/ApplicationFixture.hpp>
#include <Nebula/StackerFactory.hpp>

namespace Nebula
{

ApplicationFixture::ApplicationFixture()
{
    stacker = StackerFactory().createStacker();
}

void ApplicationFixture::stack(Strings lightFrames, std::string output)
{
    filesToRemove.add(output);
    stacker->setLightFrames(lightFrames);
    stacker->stack(output);
}

}
