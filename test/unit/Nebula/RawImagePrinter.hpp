#ifndef RAWIMAGEPRINTER_HPP
#define RAWIMAGEPRINTER_HPP

namespace boost
{
namespace gil
{

void PrintTo(const Nebula::RawImage& img, ::std::ostream* os)
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

}
}

#endif // RAWIMAGEPRINTER_HPP