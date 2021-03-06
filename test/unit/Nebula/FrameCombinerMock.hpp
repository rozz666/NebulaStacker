#ifndef NEBULA_FRAMECOMBINERMOCK_HPP
#define NEBULA_FRAMECOMBINERMOCK_HPP

#include <Nebula/FrameCombiner.hpp>
#include <gmock/gmock.h>
#include <boost/shared_ptr.hpp>

namespace Nebula
{

struct FrameCombinerMock : FrameCombiner
{
    MOCK_CONST_METHOD0(getCombinedFrame, RawImage());
    MOCK_METHOD1(addFrame, void(const RawImage&));
};

typedef boost::shared_ptr<FrameCombinerMock> FrameCombinerMockPtr;

}

#endif // NEBULA_FRAMECOMBINERMOCK_HPP
