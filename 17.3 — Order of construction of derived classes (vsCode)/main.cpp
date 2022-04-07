#include <iostream>

class Base
{
public:
    int m_id{};

    Base(int id = 0)
        : m_id{ id }
    {
    }

    int getID() const { return m_id; }
};

class Derived: public Base
{
public:
    double m_cost{};

    Derived(double cost = 0.0)
        : m_cost{ cost }
    {
    }

    double getCost() const { return m_cost; }
};

class A
{
public:
    A()
    {
        std::cout << "A\n";
    }
};

class B: public A
{
public:
    B()
    {
        std::cout << "B\n";
    }
};

class C: public B
{
public:
    C()
    {
        std::cout << "C\n";
    }
};

class D: public C
{
public:
    D()
    {
        std::cout << "D\n";
    }
};

int main()
{

    //Order of construction for inheritance chains:
    std::cout << "Constructing A: \n";
    A a;

    std::cout << "Constructing B: \n";
    B b;

    std::cout << "Constructing C: \n";
    C c;

    std::cout << "Constructing D: \n";
    D d;


    return 0;
}