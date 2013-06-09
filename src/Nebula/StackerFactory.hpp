#ifndef NEBULA_STACKERFACTORY_HPP
#define NEBULA_STACKERFACTORY_HPP
#include <Nebula/Stacker.hpp>

namespace Nebula
{

struct StackerFactory
{
    StackerPtr createStacker();
};

}

#endif // NEBULA_STACKERFACTORY_HPP
