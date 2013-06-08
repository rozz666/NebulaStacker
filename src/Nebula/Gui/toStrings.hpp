#ifndef NEBULA_TOSTRINGS_HPP
#define NEBULA_TOSTRINGS_HPP
#include <Nebula/Strings.hpp>
#include <QStringList>

namespace Nebula
{

Strings toStrings(const QStringList& list)
{
    Strings s;
    s.reserve(list.size());
    for (auto e : list)
        s.push_back(e.toStdString());
    return s;
}

}

#endif // NEBULA_TOSTRINGS_HPP
