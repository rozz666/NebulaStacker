#ifndef NEBULA_IMAGEREADERMOCK_HPP
#define NEBULA_IMAGEREADERMOCK_HPP
#include <Nebula/ImageReader.hpp>
#include <gmock/gmock.h>

namespace Nebula
{

struct ImageReaderMock : ImageReader
{
    MOCK_METHOD1(readImage, RawImage(const std::string&));
};

}

#endif // NEBULA_IMAGEREADERMOCK_HPP
