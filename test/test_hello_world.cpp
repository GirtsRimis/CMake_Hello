#define BOOST_TEST_MODULE Test
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include "say_hello/hello_world.h"

BOOST_AUTO_TEST_CASE(first_test)
{
    BOOST_CHECK_EQUAL(2, hello::sum(1, 1));
}