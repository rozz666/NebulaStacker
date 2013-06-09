#ifndef NEBULA_FRAMEAVERAGERFACTORY_HPP
#define NEBULA_FRAMEAVERAGERFACTORY_HPP
#include <Nebula/FrameCombinerFactory.hpp>

namespace Nebula
{

struct FrameAveragerFactory : FrameCombinerFactory
{
    virtual FrameCombinerPtr createFrameCombiner();
};

}

#endif // NEBULA_FRAMEAVERAGERFACTORY_HPP
