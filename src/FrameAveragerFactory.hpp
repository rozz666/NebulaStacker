#ifndef FRAMEAVERAGERFACTORY_HPP
#define FRAMEAVERAGERFACTORY_HPP
#include "FrameCombinerFactory.hpp"

struct FrameAveragerFactory : FrameCombinerFactory
{
    virtual FrameCombinerPtr createFrameCombiner();
};

#endif // FRAMEAVERAGERFACTORY_HPP
