#ifndef APPLICATIONFIXTURE_HPP
#define APPLICATIONFIXTURE_HPP
#include <NebulaStacker.hpp>
#include "AutoremoveFiles.hpp"

class ApplicationFixture
{
public:
    ApplicationFixture();
    void stack(Strings lightFrames, std::string output);
private:
    NebulaStackerPtr stacker;
    AutoremoveFiles filesToRemove;
};

#endif // APPLICATIONFIXTURE_HPP
