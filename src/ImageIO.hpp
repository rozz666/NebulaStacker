#ifndef IMAGEIO_HPP
#define IMAGEIO_HPP
#include "Images.hpp"

RawImage readTiffImage(const std::string& filename);
void writeTiffImage(const std::string& filename, const RawImage& image);

#endif // IMAGEIO_HPP
