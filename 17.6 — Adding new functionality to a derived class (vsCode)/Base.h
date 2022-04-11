#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base
{
protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    void identify() const { std::cout << "I am a Base\n"; }
};

#endif // end BASE_H