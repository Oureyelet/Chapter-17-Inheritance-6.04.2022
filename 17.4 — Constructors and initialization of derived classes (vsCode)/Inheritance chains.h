#ifndef INHERITANCE_CHAINS_H
#define INHERITANCE_CHAINS_H

#include <iostream>

class A
{
public:
    A(int a)
    {
        std::cout << "A: " << a << '\n';
    }
};

class B: public A
{
public:
    B(int a, double b)
        : A{ a }
    {
        std::cout << "B: " << b << '\n';
    }
};

class C: public B
{
public:
    int m_a{};

    C(int a, double b, char c)
        : B{ a, b }
    {
        std::cout << "C: " << c << '\n';
    }
};

#endif // end INHERITANCE_CHAINS_H