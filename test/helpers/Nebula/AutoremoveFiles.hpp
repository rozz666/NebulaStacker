#ifndef AUTOREMOVEFILES_HPP
#define AUTOREMOVEFILES_HPP
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

#endif // AUTOREMOVEFILES_HPP
