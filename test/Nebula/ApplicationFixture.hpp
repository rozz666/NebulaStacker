#ifndef APPLICATIONFIXTURE_HPP
#define APPLICATIONFIXTURE_HPP
#include <Nebula/Stacker.hpp>
#include <Nebula/AutoremoveFiles.hpp>

namespace Nebula
{

class ApplicationFixture
{
public:
    ApplicationFixture();
    void stack(Strings lightFrames, std::string output);
private:
    StackerPtr stacker;
    AutoremoveFiles filesToRemove;
};

}

#endif // APPLICATIONFIXTURE_HPP
