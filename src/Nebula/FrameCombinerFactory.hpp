#ifndef NEBULA_FRAMECOMBINERFACTORY_HPP
#define NEBULA_FRAMECOMBINERFACTORY_HPP
#include <Nebula/FrameCombiner.hpp>

namespace Nebula
{

struct FrameCombinerFactory
{
    virtual ~FrameCombinerFactory() { }
    virtual FrameCombinerPtr createFrameCombiner() = 0;
};

}

#endif // NEBULA_FRAMECOMBINERFACTORY_HPP
