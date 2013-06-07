#ifndef FRAMECOMBINER_HPP
#define FRAMECOMBINER_HPP
#include "Images.hpp"
#include <boost/shared_ptr.hpp>

namespace Nebula
{

struct FrameCombiner
{
    virtual ~FrameCombiner() { }
    virtual void addFrame(const RawImage& frame) = 0;
    virtual RawImage getCombinedFrame() const = 0;
};

typedef boost::shared_ptr<FrameCombiner> FrameCombinerPtr;

}

#endif // FRAMECOMBINER_HPP
