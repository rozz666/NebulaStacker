#include <Nebula/FrameAveragerFactory.hpp>
#include <Nebula/FrameAverager.hpp>
#include <boost/make_shared.hpp>

namespace Nebula
{

FrameCombinerPtr FrameAveragerFactory::createFrameCombiner()
{
    return boost::make_shared<FrameAverager>();
}

}