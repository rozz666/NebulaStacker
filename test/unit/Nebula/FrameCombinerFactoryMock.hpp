#ifndef NEBULA_FRAMECOMBINERFACTORYMOCK_HPP
#define NEBULA_FRAMECOMBINERFACTORYMOCK_HPP
#include <Nebula/FrameCombinerFactory.hpp>
#include <gmock/gmock.h>

namespace Nebula
{

struct FrameCombinerFactoryMock : FrameCombinerFactory
{
    MOCK_METHOD0(createFrameCombiner, FrameCombinerPtr());
};

}

#endif // NEBULA_FRAMECOMBINERFACTORYMOCK_HPP
