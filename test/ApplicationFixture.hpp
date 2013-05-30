#ifndef APPLICATIONFIXTURE_HPP
#define APPLICATIONFIXTURE_HPP
#include <NebulaStacker.hpp>
#include "AutoremoveFiles.hpp"

class ApplicationFixture
{
public:
    void stack(Strings lightFrames, std::string output);
private:
    NebulaStacker stacker;
    AutoremoveFiles filesToRemove;
};

#endif // APPLICATIONFIXTURE_HPP
