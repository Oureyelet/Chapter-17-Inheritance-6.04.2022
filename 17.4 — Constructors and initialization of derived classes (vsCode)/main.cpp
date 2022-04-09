#include <iostream>
#include "person.h"
#include "Inheritance chains.h"
#include "quiztime.h"

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

    Derived(double cost = 0.0, int id = 0)
        : Base{ id } // Call Base(int) constructor with value id!
        , m_cost{ cost } 
    {
        
    }

    double getCost() const { return m_cost; }
};

class Parent
{
private:// our member is now private
    int m_id{};

public:
    Parent(int id = 0)
        : m_id{ id }
    {
    }

    int getID() const { return m_id; }
};

class Child: public Parent
{
private: // our member is now private
    double m_cost{};

public:
    Child(double cost = 0.0, int id = 0)
        : Parent{ id } // Call Parent(int) constructor with value id! 
        , m_cost{ cost }
    {
    }

    void printInfo(const Child& child)
    {
        std::cout << "Id: " << child.getID() << '\n';
        std::cout << "Cost: " << child.getCost() << '\n';
    }

    double getCost() const { return m_cost; }
};


int main()
{
    Base base{ 5 }; // use Base(int) constructor

    Derived derived{ 1.3 }; // use Derived(double) constructor

    //Initializing base class members:
    Derived coppy;
    coppy.m_id = 5;

    Derived secondClass{ 2.2, 33 };// use Derived(double, int) constructor
    std::cout << "Id: " << secondClass.getID() << '\n';
    std::cout << "Cost: " << secondClass.getCost() << '\n';

    //Now we can make our members private:
    Child sophie{ 12.3, 77 };
    sophie.printInfo(sophie);

    //Another example:
    BaseballPlayer pedro{ "Pedro Cerrano", 67, 0.342, 42 };

    std::cout << pedro.getName() << '\n';
    std::cout << pedro.getAge() << '\n';
    std::cout << pedro.getBattingAverage() << '\n';
    std::cout << pedro.getHomeRuns() << '\n';

    //Inheritance chains:
    C c{5, 4.4, 'U'};

    //Destructors:

    //Quiz time!: go see 'Quiz time.h'
    const Apple a{ "Red delicious", "red", 4.2 };
    std::cout << a;

    const Banana b{ "Cavendish", "yellow" };    
    std::cout << b;

    return 0;
}