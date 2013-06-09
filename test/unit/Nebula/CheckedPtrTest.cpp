#include <Nebula/CheckedPtr.hpp>
#include <gtest/gtest.h>
#include <boost/shared_ptr.hpp>

namespace Nebula
{

TEST(CheckedPtrTest, should_throw_NullPointer_when_accessed_while_uninitialized)
{
    const CheckedPtr<int> p;
    ASSERT_THROW(p.operator*(), NullPointer);
    ASSERT_THROW(p.operator->(), NullPointer);
}

TEST(CheckedPtrTest, should_store_given_pointer)
{
    long n = 99;
    const CheckedPtr<long> p(&n);
    ASSERT_EQ(n, p.operator*());
    ASSERT_EQ(n, *p.operator->());
}

}