#ifndef NEBULA_TRANSLATEDFRAMES_HPP
#define NEBULA_TRANSLATEDFRAMES_HPP
#include <Nebula/Images.hpp>
#include <Nebula/Point.hpp>

namespace Nebula {

RawImages translatedFrames(const RawImage& frame, Points offsets);

}

#endif // NEBULA_TRANSLATEDFRAMES_HPP
