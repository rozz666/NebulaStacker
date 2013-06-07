#include <Nebula/AutoremoveFiles.hpp>
#include <cstdio>

namespace Nebula
{

AutoremoveFiles::~AutoremoveFiles()
{
    for (auto f : files)
        std::remove(f.c_str());
}

void AutoremoveFiles::add(std::string filename)
{
    files.push_back(filename);
}

}
