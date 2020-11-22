#include <iostream>
#include "hello_world.h"

void hello::print_hello()
{
    std::cout << "Hello World! Version " << SAY_HELLO_VERSION << "\n";
}

int hello::sum(int a, int b)
{
    return a + b;
}