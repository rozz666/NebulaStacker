#ifndef NEBULASTACKER_HPP
#define NEBULASTACKER_HPP
#include <Nebula/Strings.hpp>
#include <Nebula/ImageReader.hpp>
#include <Nebula/ImageWriter.hpp>
#include <Nebula/FrameCombinerFactory.hpp>
#include <boost/shared_ptr.hpp>

namespace Nebula
{

class NebulaStacker
{
public:
    NebulaStacker(ImageReader& imageReader, ImageWriter& imageWriter, FrameCombinerFactory& frameCombinerFactory);
    void setLightFrames(const Strings& lightFrames);
    void stack(const std::string& outputFilename);
private:
    ImageReader& imageReader;
    ImageWriter& imageWriter;
    FrameCombinerFactory& frameCombinerFactory;
    Strings lightFrames;
};

typedef boost::shared_ptr<NebulaStacker> NebulaStackerPtr;

}

#endif // NEBULASTACKER_HPP
