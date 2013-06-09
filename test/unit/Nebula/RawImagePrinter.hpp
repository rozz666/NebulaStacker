#ifndef NEBULA_RAWIMAGEPRINTER_HPP
#define NEBULA_RAWIMAGEPRINTER_HPP
#include <Nebula/Images.hpp>

namespace boost
{
namespace gil
{

inline void PrintTo(const Nebula::RawImage& img, ::std::ostream* os)
{
    *os << "RawImage[ " << img.width() << " x " << img.height() << " :";
    for (auto p : const_view(img))
    {
        *os << " (";
        static_for_each(p, [=](Nebula::RawChannel ch)  { *os << " " << ch; });
        *os << " )";
    }
    *os << " ]";
}

template <typename T>
inline void PrintTo(const point2<T>& p, ::std::ostream* os)
{
    *os << "(" << p.x << ", " << p.y << ")";
}

}
}

#endif // NEBULA_RAWIMAGEPRINTER_HPP
