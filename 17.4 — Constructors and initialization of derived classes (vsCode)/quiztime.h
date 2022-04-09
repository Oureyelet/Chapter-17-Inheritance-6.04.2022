#ifndef QUIZTIME_H
#define QUIZTIME_H

#include <iostream>
#include <string>

class Fruit
{
private:
    std::string m_name{};
    std::string m_color{};

public:
    Fruit(const std::string& name = "", const std::string& color = "")
        : m_name{ name }, m_color{ color }
    {
    }

    const std::string& getName() const { return m_name; }
    const std::string& getColor() const { return m_color; }
};

class Apple: public Fruit
{
private:
    double m_fibre{};

public:
    Apple(const std::string& name = "", const std::string& color = "", double fibre = 0.0 )
        : Fruit{ name, color }
        , m_fibre{ fibre }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Apple& apple)
    {
        out << "Apple" << '(' << apple.getName() << ", " << apple.getColor() << ", " << apple.m_fibre << ')' << '\n';
        return out;
    }

    double getFibre() const { return m_fibre; }
};

class Banana: public Fruit
{
public:
    Banana(const std::string& name = "", const std::string& color = "")
        : Fruit{ name, color }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Banana& banana)
    {
        out << "Banana" << '(' <<banana.getName() << ", " << banana.getColor() << ')' << '\n';
        return out;
    }
};

#endif // end QUIZTIME_H