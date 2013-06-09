#ifndef NEBULA_AUTOREMOVEFILES_HPP
#define NEBULA_AUTOREMOVEFILES_HPP
#include <Nebula/Strings.hpp>

namespace Nebula
{

class AutoremoveFiles
{
public:
    ~AutoremoveFiles();
    void add(std::string filename);
private:
    Strings files;
};

}

#endif // NEBULA_AUTOREMOVEFILES_HPP
