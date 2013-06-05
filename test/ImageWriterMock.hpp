#ifndef IMAGEWRITERMOCK_HPP
#define IMAGEWRITERMOCK_HPP
#include <ImageWriter.hpp>
#include <gmock/gmock.h>

struct ImageWriterMock : ImageWriter
{
    MOCK_METHOD2(writeImage, void(const std::string&, const RawImage&));
};

#endif // IMAGEWRITERMOCK_HPP
