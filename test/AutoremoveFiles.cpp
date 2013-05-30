#include "AutoremoveFiles.hpp"
#include <cstdio>

AutoremoveFiles::~AutoremoveFiles()
{
    for (auto f : files)
        std::remove(f.c_str());
}

void AutoremoveFiles::add(std::string filename)
{
    files.push_back(filename);
}

