#ifndef NEBULA_ENVIRONMENTFIXTURE_HPP
#define NEBULA_ENVIRONMENTFIXTURE_HPP

namespace Nebula
{

class EnvironmentFixture
{
public:
    EnvironmentFixture();
    ~EnvironmentFixture();

    void expectOpenFiles();
};

}

#endif // NEBULA_ENVIRONMENTFIXTURE_HPP
