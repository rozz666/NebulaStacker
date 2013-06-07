#ifndef NEBULASTACKERFACTORY_HPP
#define NEBULASTACKERFACTORY_HPP
#include <Nebula/Stacker.hpp>

namespace Nebula
{

struct StackerFactory
{
    StackerPtr createStacker();
};

}

#endif // NEBULASTACKERFACTORY_HPP
