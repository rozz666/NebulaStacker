#ifndef NEBULA_STACKER_HPP
#define NEBULA_STACKER_HPP
#include <Nebula/Strings.hpp>
#include <Nebula/ImageReader.hpp>
#include <Nebula/ImageWriter.hpp>
#include <Nebula/FrameCombinerFactory.hpp>
#include <boost/shared_ptr.hpp>

namespace Nebula
{

class Stacker
{
public:
    Stacker(ImageReader& imageReader, ImageWriter& imageWriter, FrameCombinerFactory& frameCombinerFactory);
    void setLightFrames(const Strings& lightFrames);
    void stack(const std::string& outputFilename);
private:
    ImageReader& imageReader;
    ImageWriter& imageWriter;
    FrameCombinerFactory& frameCombinerFactory;
    Strings lightFrames;
};

typedef boost::shared_ptr<Stacker> StackerPtr;

}

#endif // NEBULA_STACKER_HPP
