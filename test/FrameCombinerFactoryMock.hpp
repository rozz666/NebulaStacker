#ifndef FRAMECOMBINERFACTORYMOCK_HPP
#define FRAMECOMBINERFACTORYMOCK_HPP
#include <FrameCombinerFactory.hpp>
#include <gmock/gmock.h>

struct FrameCombinerFactoryMock : FrameCombinerFactory
{
    MOCK_METHOD0(createFrameCombiner, FrameCombinerPtr());
};

#endif // FRAMECOMBINERFACTORYMOCK_HPP
