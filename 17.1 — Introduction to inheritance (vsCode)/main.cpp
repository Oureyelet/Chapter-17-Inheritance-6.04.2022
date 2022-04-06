#include <iostream>
#include <string>

class Fruit
{
private:
    std::string m_name{};
    std::string m_color{};
    double m_size{};

public:
    Fruit(std::string name, std::string color, double size)
        : m_name{ name }, m_color{ color }, m_size{ size }
    {
    }

    void getInfo()
    {
        std::cout << m_name << " has a " << m_color << " color and " << m_size << " size\n";
    }

    friend std::ostream& operator<<(std::ostream& out, const Fruit& fruit)
    {
        out << fruit.m_name << " has a " << fruit.m_color << " color and " << fruit.m_size << " size\n";
        return out;
    }

};

int main()
{
    std::cout << "Hello World\n";

    Fruit kiwi{"Kiwi", "brown", 2.2};

    std::cout << kiwi;

    //Hierarchies:

    //A look ahead:


    return 0;
}