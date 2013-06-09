#ifndef FRAMEAVERAGERFACTORY_HPP
#define FRAMEAVERAGERFACTORY_HPP
#include <Nebula/FrameCombinerFactory.hpp>

namespace Nebula
{

struct FrameAveragerFactory : FrameCombinerFactory
{
    virtual FrameCombinerPtr createFrameCombiner();
};

}

#endif // FRAMEAVERAGERFACTORY_HPP
