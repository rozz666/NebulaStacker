#ifndef NEBULASTACKERFACTORY_HPP
#define NEBULASTACKERFACTORY_HPP
#include <Nebula/NebulaStacker.hpp>

namespace Nebula
{

struct NebulaStackerFactory
{
    NebulaStackerPtr createNebulaStacker();
};

}

#endif // NEBULASTACKERFACTORY_HPP
