#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base
{
private:
    void print() const
    {
        std::cout << "Base\n";
    }

protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    void identify() const { std::cout << "I am a Base\n"; }

    friend std::ostream& operator<<(std::ostream& out, const Base& b)
    {
        out << "In Base\n";
        out << b.m_value << '\n';
        return out;
    }
};

#endif // end BASE_H