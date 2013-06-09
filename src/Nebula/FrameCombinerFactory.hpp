#ifndef FRAMECOMBINERFACTORY_HPP
#define FRAMECOMBINERFACTORY_HPP
#include <Nebula/FrameCombiner.hpp>

namespace Nebula
{

struct FrameCombinerFactory
{
    virtual ~FrameCombinerFactory() { }
    virtual FrameCombinerPtr createFrameCombiner() = 0;
};

}

#endif // FRAMECOMBINERFACTORY_HPP
