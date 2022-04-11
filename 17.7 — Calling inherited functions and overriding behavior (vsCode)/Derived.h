#ifndef DERIVED_H
#define DERIVED_H

#include <iostream>
#include "Base.h"

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    void print() const
    {
        std::cout << "Derived\n";
    }

    int getValue() const { return m_value; }
    void identify() const 
    { 
        Base::identify(); // call Base::identify() first
        std::cout << "Im a derived!\n"; 
    }
};

#endif // end DERIVED_H