#include <iostream>

class Base
{
private:
    int m_value{};

public:
    int m_hight{};

    Base(int value)
        : m_value{ value }
    {
    }

    int getValue() const { return m_value; }

protected:
    void printValue() const { std::cout << m_value << '\n'; }
};

class Derived: public Base
{
private:
    using Base::m_hight; // we changed m_hight from public to private

public:
    Derived(int value)
        : Base{ value }
    {
    }

    // Base::printValue was inherited as protected, so the public has no access
    // But we're changing it to public via a using declaration  
    using Base::printValue; // note: no parenthesis here

    int getValue() = delete; // mark this function as inaccessible
};

int main()
{
    //Changing an inherited member’s access level:
    Derived derived{ 7 };
    // printValue is public in Derived, so this is okay
    derived.printValue();// prints 7

    //Hiding functionality:
    Derived derii{ 23 };
    // We can still access the function deleted in the Derived class through the Base class
    std::cout << static_cast<Base&>(derii).getValue() << '\n'; 




    return 0;
}