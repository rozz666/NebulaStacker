#ifndef NEBULA_ENVIRONMENTFIXTURE_HPP
#define NEBULA_ENVIRONMENTFIXTURE_HPP
#include <Nebula/Strings.hpp>
#include <Nebula/AutoremoveFiles.hpp>
#include <Nebula/FrameFiles.hpp>

namespace Nebula
{

class EnvironmentFixture
{
public:
    EnvironmentFixture();
    ~EnvironmentFixture();

    void expectOpenFiles(Strings files = Strings());
    void expectSaveFile(std::string file);
    void expectSaveFileAndCancel();
    void assertFileExists(std::string file);
    Strings generateLightFrames(unsigned count);

private:
    FrameFiles frameFiles;
    AutoremoveFiles filesToRemove;
};

}

#endif // NEBULA_ENVIRONMENTFIXTURE_HPP
