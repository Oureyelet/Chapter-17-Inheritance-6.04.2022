#include <iostream>
#include <string>

class Person
{
private:
    std::string m_name{};
    int m_age{};

public:
    Person(const std::string& name, int age)
        : m_name{ name }, m_age{ age }
    {
    }

    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }

};

class Employee
{
private:
    std::string m_employer{};
    double m_wage{};

public:
    Employee(const std::string& employer, double wage)
        : m_employer{ employer }, m_wage{ wage }
    {
    }

    std::string getEmployer() const { return m_employer; }
    double getWage() const { return m_wage; }
};

// Teacher publicly inherits Person and Employee
class Teacher: public Person, public Employee
{
private:
    int m_teachesGrade{};

public:
    Teacher(const std::string& name, const std::string& employer, int age, double wage, int teachesGrade)
        : Person{ name, age }, Employee{ employer, wage }
        , m_teachesGrade{ teachesGrade }
    {
    }

    int getTeachesGrade() const { return m_teachesGrade; }
};

int main()
{
    //Problems with multiple inheritance:
    Teacher kolo123{ "Jan Kolanko", "NiftyLift", 122, 11.75, 7 };
    std::cout << "Name: " << kolo123.getName() << '\n';
    std::cout << "Employer: " << kolo123.getEmployer() << '\n';
    std::cout << "Age: " << kolo123.getAge() << '\n';
    std::cout << "Wage: " << kolo123.getWage() << '\n';
    std::cout << "Grade: " << kolo123.getTeachesGrade() << '\n';

    //Is multiple inheritance more trouble than it’s worth?:

    return 0;
}