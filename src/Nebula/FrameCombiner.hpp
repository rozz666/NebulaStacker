#ifndef NEBULA_FRAMECOMBINER_HPP
#define NEBULA_FRAMECOMBINER_HPP
#include <Nebula/Images.hpp>
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

#endif // NEBULA_FRAMECOMBINER_HPP
