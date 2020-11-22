#include <iostream>
#include <say_hello/hello_world.h>

int main()
{
    hello::print_hello();
    std::cout << hello::sum(1, 1) << "\n";
    return 0;
}