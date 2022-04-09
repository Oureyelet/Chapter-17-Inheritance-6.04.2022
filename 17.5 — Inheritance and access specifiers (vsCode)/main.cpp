#include <iostream>

class Base
{
private:
    int m_private{};// can only be accessed by Base members and friends (not derived classes)

protected:
    int m_protected{};// can be accessed by Base members, friends, and derived classes

public:
    int m_public{};// can be accessed by anybody
};

class Derived: public Base
{
public:
    Derived()
    {
        m_public = 1;// allowed: can access public base members from derived class
        m_protected = 2;// allowed: can access protected base members from derived class

        // m_private = 3 not allowed: can not access private base members from derived class
    }
};

int main()
{
    Base a;
    a.m_public = 5;

    //The protected access specifier:
    Base b;
    b.m_public = 1;
    /*
    base.m_protected = 2; // not allowed: can not access protected members from outside class
    base.m_private = 3; // not allowed: can not access private members from outside class
    */

    //So when should I use the protected access specifier?:
    
    


    return 0;
}