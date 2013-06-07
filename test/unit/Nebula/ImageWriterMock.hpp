#ifndef IMAGEWRITERMOCK_HPP
#define IMAGEWRITERMOCK_HPP
#include <Nebula/ImageWriter.hpp>
#include <gmock/gmock.h>

namespace Nebula
{

struct ImageWriterMock : ImageWriter
{
    MOCK_METHOD2(writeImage, void(const std::string&, const RawImage&));
};

}

#endif // IMAGEWRITERMOCK_HPP
