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

// Inherit from Base publicly
class Pub: public Base
{
};

// Inherit from Base protectedly
class Pro: protected Base
{
};

// Inherit from Base privately
class Pri: private Base
{
};

// Defaults to private inheritance
class Def: Base
{
};

class ExampleBase
{
public:
    int m_public{};

protected:
    int m_protected{};

private:
    int m_private{};

};

class ExampleDerivedPublic : public ExampleBase // note: public inheritance
{
    // Public inheritance means:
    // Public inherited members stay public (so m_public is treated as public)
    // Protected inherited members stay protected (so m_protected is treated as protected)
    // Private inherited members stay inaccessible (so m_private is inaccessible)

public:
    ExampleDerivedPublic()
    {
        m_public = 1; // okay: m_public was inherited as public
        m_protected = 2;// okay: m_protected was inherited as protected
        // m_private = 3; // not okay: m_private is inaccessible from derived class
    }

};

class ExampleDerivedPrivate : private ExampleBase // note: private inheritance
{
    // Private inheritance means:
    // Public inherited members become private (so m_public is treated as private)
    // Protected inherited members become private (so m_protected is treated as private)
    // Private inherited members stay inaccessible (so m_private is inaccessible)

public:
    ExampleDerivedPrivate()
    {
        m_public = 1; // okay: m_public is now private in ExampleDerivedPrivate
        m_protected = 2;// okay: m_protected is now private in ExampleDerivedPrivate
        // m_private = 3; // not okay: derived classes can't access private members in the base class
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

    //Different kinds of inheritance, and their impact on access:

    //Public inheritance:
    ExampleBase exampleBase;// Outside access uses the access specifiers of the class being accessed.
    exampleBase.m_public = 1;// okay: m_public is public in Base
    //exampleBase.m_protected = 2;// not okay: m_protected is protected in Base
    //exampleBase.m_private = 3;// not okay: m_private is private in Base

    ExampleDerivedPublic exampleDerived;
    exampleDerived.m_public = 1;// okay: m_public is public in Pub
    //exampleDerived.m_protected = 2;// not okay: m_protected is protected in Pub
    //exampleDerived.m_private = 3;// not okay: m_private is inaccessible in Pub

    //Protected inheritance:

    //Private inheritance:
    ExampleBase anotherExampleBase;
    anotherExampleBase.m_public = 1;// okay: m_public is public in Base
    //anotherExampleBase.m_protected = 2;// not okay: m_protected is protected in Base
    //anotherExampleBase.m_private = 3;// not okay: m_private is private in Base

    ExampleDerivedPrivate exampleDerivedPrivate;// Outside access uses the access specifiers of the class being accessed.
    // In this case, the access specifiers of base.
    //exampleDerivedPrivate.m_public = 1;// not okay: m_public is now private in ExampleDerivedPrivate
    //exampleDerivedPrivate.m_protected = 2;// not okay: m_protected is now private in ExampleDerivedPrivate
    //exampleDerivedPrivate.m_private = 3;// not okay: m_private is inaccessible in ExampleDerivedPrivate
        
    return 0;
}