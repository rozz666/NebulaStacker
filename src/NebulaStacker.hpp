#ifndef NEBULASTACKER_HPP
#define NEBULASTACKER_HPP
#include "Strings.hpp"

class NebulaStacker
{
public:
    void setLightFrames(const Strings& lightFrames);
    void stack(const std::string& outputFilename);
private:
    Strings lightFrames;
};

#endif // NEBULASTACKER_HPP
