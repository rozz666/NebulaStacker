#ifndef IMAGEREADERMOCK_HPP
#define IMAGEREADERMOCK_HPP
#include <ImageReader.hpp>
#include <gmock/gmock.h>

struct ImageReaderMock : ImageReader
{
    MOCK_METHOD1(readImage, RawImage(const std::string&));
};

#endif // IMAGEREADERMOCK_HPP
