#ifndef FRAMEAVERAGER_HPP
#define FRAMEAVERAGER_HPP
#include <Nebula/FrameCombiner.hpp>

namespace Nebula
{

class FrameAverager : public FrameCombiner
{
public:
    void addFrame(const RawImage& frame);
    RawImage getCombinedFrame() const;
private:
    AccumImage accumulator;
    std::size_t frameCount = 0;
};

}

#endif // FRAMEAVERAGER_HPP
