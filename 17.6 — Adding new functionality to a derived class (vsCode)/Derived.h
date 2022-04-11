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

    int getValue() const { return m_value; }
};

#endif // end DERIVED_H