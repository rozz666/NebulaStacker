#ifndef MAKEWITHDEPENDENCIES_HPP
#define MAKEWITHDEPENDENCIES_HPP

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

#endif // MAKEWITHDEPENDENCIES_HPP
