#include <Nebula/FrameAverager.hpp>
#include <boost/gil/extension/numeric/pixel_numeric_operations.hpp>
#include <boost/gil/extension/numeric/algorithm.hpp>

namespace Nebula
{

void FrameAverager::addFrame(const RawImage& frame)
{
    if (view(accumulator).size() == 0)
    {
        accumulator.recreate(frame.dimensions());
        fill_pixels(view(accumulator), Color::black());
    }
    boost::gil::transform_pixels(const_view(frame), const_view(accumulator), view(accumulator), boost::gil::pixel_plus_t<RawPixel, AccumPixel, AccumPixel>());
    ++frameCount;
}

RawImage FrameAverager::getCombinedFrame() const
{
    RawImage output(accumulator.dimensions());
    boost::gil::view_divides_scalar<AccumPixel>(const_view(accumulator), frameCount, view(output));
    return output;
}

}