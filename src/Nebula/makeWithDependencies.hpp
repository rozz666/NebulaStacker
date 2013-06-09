#ifndef NEBULA_MAKEWITHDEPENDENCIES_HPP
#define NEBULA_MAKEWITHDEPENDENCIES_HPP

#include <boost/make_shared.hpp>

namespace Nebula
{

template <typename Container, typename Object>
boost::shared_ptr<Object> makeWithDependencies(Object Container::*object)
{
    auto container = boost::make_shared<Container>();
    return boost::shared_ptr<Object>(container, &((*container).*object));
}

}

#endif // NEBULA_MAKEWITHDEPENDENCIES_HPP
