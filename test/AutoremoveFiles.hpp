#ifndef AUTOREMOVEFILES_HPP
#define AUTOREMOVEFILES_HPP
#include <Strings.hpp>

class AutoremoveFiles
{
public:
    ~AutoremoveFiles();
    void add(std::string filename);
private:
    Strings files;
};

#endif // AUTOREMOVEFILES_HPP
