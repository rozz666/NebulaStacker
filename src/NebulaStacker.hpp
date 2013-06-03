#ifndef NEBULASTACKER_HPP
#define NEBULASTACKER_HPP
#include "Strings.hpp"
#include "ImageReader.hpp"
#include <boost/shared_ptr.hpp>

class NebulaStacker
{
public:
    NebulaStacker(ImageReader& imageReader);
    void setLightFrames(const Strings& lightFrames);
    void stack(const std::string& outputFilename);
private:
    ImageReader& imageReader;
    Strings lightFrames;
};

typedef boost::shared_ptr<NebulaStacker> NebulaStackerPtr;

#endif // NEBULASTACKER_HPP
