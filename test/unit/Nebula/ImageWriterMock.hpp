#ifndef NEBULA_IMAGEWRITERMOCK_HPP
#define NEBULA_IMAGEWRITERMOCK_HPP
#include <Nebula/ImageWriter.hpp>
#include <gmock/gmock.h>

namespace Nebula
{

struct ImageWriterMock : ImageWriter
{
    MOCK_METHOD2(writeImage, void(const std::string&, const RawImage&));
};

}

#endif // NEBULA_IMAGEWRITERMOCK_HPP
