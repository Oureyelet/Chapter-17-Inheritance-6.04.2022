#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person
{
public:
    std::string m_name{};
    int m_age{};

    Person(const std::string& name = "", int age = 0 )
        : m_name{ name }
        , m_age{ age }
    {
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
};

// BaseballPlayer publicly inheriting Person
class BaseballPlayer: public Person
{
public:
    double m_battingAverage{};
    int m_homeRuns{};

    BaseballPlayer(const std::string& name = "", int age = 0,
                   double battingAverage = 0.0, int homeRuns = 0)
        : Person{ name, age } // call Person(const std::string&, int) to initialize these fields
        , m_battingAverage{ battingAverage } , m_homeRuns{ homeRuns }
    {
    }

    double getBattingAverage() const { return m_battingAverage; }
    int getHomeRuns() const { return m_homeRuns; }

};

#endif // finish PERSON_H