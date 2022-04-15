#include <iostream>
#include <string>
#include <string_view> 
#include <array>

class Creature
{
protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_damage{};
    int m_gold{};

public:
    Creature(std::string_view name, char symbol, int health, int damage, int gold)
		: m_name{ name }
		, m_symbol{ symbol }
		, m_health{ health }
		, m_damage{ damage }
		, m_gold{ gold }
	{
	}

    const std::string& getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHp() const { return m_health; }
    int getAttack() const { return m_damage; }
    int getGold() const { return m_gold; }

    void reduceHealth(int hp){ m_health -= hp; }
    bool isDead() const { return m_health <= 0; }
    void addGold(int gold){ m_gold += gold; }
};

class Player: public Creature
{
private:
    int m_lvl{ 1 };

public:
    Player(std::string_view name)
        : Creature{ name, '@', 10, 1, 0 }
    { 
    }

    void levelUp()
    {
       ++m_lvl;
       ++m_damage; 
    }

    int getLvl() const { return m_lvl; }
    bool hasWon() const { return m_lvl >= 20; }

    friend std::ostream& operator<<(std::ostream& out, const Player& player)
    {
        out << "Welcome, " << player.getName() << ".\n";
        out << "You have " << player.getHp() << " health and are carrying " << player.getGold() << "  gold.\n";
        return out;
    }
};

class Monster: public Creature
{
public:
    enum class Type
    {
        type_dragon,
        type_orc, 
        type_slime,
        max_types,
    }; 

private:
    static const Creature& getDefaultCreature(Type type)
    {
        static const std::array<Creature, static_cast<std::size_t>(Type::max_types)>monsterData
        {
            {
                { "dragon", 'D', 20, 4, 100 },
                { "orc", 'o', 4, 2, 25 },
                { "slime", 's', 1, 1, 10 }
            }
        };
        return monsterData.at(static_cast<std::size_t>(type));
    }

public:
    Monster(const Type& type)
        : Creature{ getDefaultCreature(type) }
    {
    }
};

std::string ask_for_User_name()
{
    std::string name{};
    std::cout << "Enter your name: ";
    std::cin >> name;

    return name;
}

int main()
{
    //check C++ version:
    if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";


    Creature o{ "orc", 'o', 4, 2, 10 };
    o.addGold(5);
    o.reduceHealth(1);

    std::cout << "The " << o.getName() << " has " << o.getHp() << " health and is carrying " << o.getGold() << " gold.\n";

    Player player1{ ask_for_User_name() };
    std::cout << player1;

    Monster m{ Monster::Type::type_orc };
    std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n"; 

    



    return 0;
}