#include <iostream>
#include "Derived.h"

int main()
{
    //Adding new functionality to a derived class:
    Derived derived{ 5 };
    std::cout << "derived has value " << derived.getValue() << '\n';

    return 0;
}