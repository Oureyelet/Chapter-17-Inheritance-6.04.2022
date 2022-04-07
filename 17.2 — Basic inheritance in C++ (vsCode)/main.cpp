#include <iostream>
#include <string>

class Person
{
// In this example, we're making our members public for simplicity
public:
    std::string m_name{};
    int m_age{};

    Person(const std::string& name = "", int age = 0)
        : m_name{ name }, m_age{ age }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Person& person)
    {
        out << person.m_name << " is " << person.m_age << " years old\n";
        return out;
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
};

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
// In this example, we're making our members public for simplicity
public:
    double m_battingAverage{};
    int m_homeRuns{};
    
    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
        : m_battingAverage{ battingAverage }, m_homeRuns{ homeRuns }
    {
    }
};

class Employee : public Person
{
public:
    double m_hourlySalary{};
    long m_employeeID{};

    Employee(double hourlySalary = 0.0, long employeeID = 0)
        : m_hourlySalary{ hourlySalary }, m_employeeID{ employeeID }
    {
    }

    void printNameAndSalary() const
    {
        std::cout << m_name << ": " << m_hourlySalary << '\n';
    }
};  

class Supervisor : public Person
{
public:
    // This Supervisor can oversee a max of 5 employees
    long m_overseesIDs[5]{};
};

int main()
{
    
    //A Person class:

    //A BaseballPlayer class:

    //Making BaseballPlayer a derived class:
    
    BaseballPlayer joe;// Create a new BaseballPlayer object

    // Assign it a name (we can do this directly because m_name is public)
    joe.m_name = "Joe"; 

    // Print out the name
    std::cout << joe.getName() << '\n';// use the getName() function we've acquired from the Person base class

    //An Employee derived class:
    Employee frank{ 20.25, 12345 };
    frank.m_name = "Frank";

    frank.printNameAndSalary();

    frank.m_age = 30;

    std::cout << frank << '\n';

    //Inheritance chains:

    //Why is this kind of inheritance useful?:
    







    return 0;
}