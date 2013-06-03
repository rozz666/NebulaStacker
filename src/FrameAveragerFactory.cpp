#include "FrameAveragerFactory.hpp"
#include "FrameAverager.hpp"
#include <boost/make_shared.hpp>

FrameCombinerPtr FrameAveragerFactory::createFrameCombiner()
{
    return boost::make_shared<FrameAverager>();
}
