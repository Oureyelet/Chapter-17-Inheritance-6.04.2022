#include <iostream>
#include "Derived.h"

int main()
{
    //Calling a base class function:
    Base base{ 5 };
    base.identify();

    Derived derived{ 7 };
    derived.identify();

    //Redefining behaviors:
    Derived der{ 3 };
    der.print();

    //Adding to existing functionality:
    Derived another{ 33 };
    another.identify();

    std::cout << another << '\n';


    return 0;
}