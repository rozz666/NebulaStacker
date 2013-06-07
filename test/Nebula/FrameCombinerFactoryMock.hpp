#ifndef FRAMECOMBINERFACTORYMOCK_HPP
#define FRAMECOMBINERFACTORYMOCK_HPP
#include <Nebula/FrameCombinerFactory.hpp>
#include <gmock/gmock.h>

namespace Nebula
{

struct FrameCombinerFactoryMock : FrameCombinerFactory
{
    MOCK_METHOD0(createFrameCombiner, FrameCombinerPtr());
};

}

#endif // FRAMECOMBINERFACTORYMOCK_HPP
