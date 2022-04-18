#include <iostream>
#include <string>
#include <string_view> 
#include <array>
#include <random> // for std::mt19937
#include "random.hpp" // for Random::get(min, max)
#include <cassert>

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
        out << "Welcome, " << player.getName() << "\n";
        //out << "You have " << player.getHp() << " health and are carrying " << player.getGold() << "  gold.\n";
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

    static const Creature& getDefaultCreature(Type type)
    {
        static const std::array<Creature, static_cast<std::size_t>(Type::max_types)>monsterData
        {
            {   // name___symbol_hp_damage_ goold
                { "dragon", 'D', 20, 4, 100 },
                { "orc", 'o', 4, 2, 25 },
                { "slime", 's', 1, 1, 10 }
            }
        };
        return monsterData.at(static_cast<std::size_t>(type));
    }

    static Type getRandomMonster()
    {
        using Random = effolkronium::random_static;
        return static_cast<Type>( Random::get(0, (static_cast<int>(Type::max_types)-1) ) );
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

void fightMonster(Player& player)
{
    Monster mr{ Monster::getRandomMonster() };
    std::cout << "You have encountered a " << mr.getName() << " (" << mr.getSymbol() << ")\n.";

    char run_or_fight{};

    while (player.getHp() > 0 || mr.getHp() > 0 )
    {
        std::cout << "(R)un or (F)ight: ";
        std::cin >> run_or_fight;
        
        if(run_or_fight == 'f' || run_or_fight == 'F')
        {
            std::cout << "You hit the " << mr.getName() << " for " << player.getAttack() << " damage\n.";
            mr.reduceHealth( player.getAttack() );

                if(player.getAttack() >= mr.getHp())
                {
                    std::cout << "You killed the " << mr.getName() << '.\n';
                    player.levelUp();
                    player.addGold( mr.getGold() );
                    
                    std::cout << "You are now level " << player.getLvl() << '.\n';
                    std::cout << "You found " << mr.getGold()  << " gold.\n";
                    break;
                }
                else if(mr.getAttack() >= player.getHp())
                {
                    std::cout << "You died at level " << player.getLvl() << " and with " << player.getGold() << " gold.\n;
                    Too bad you can’t take it with you!

                    std::cout << "The " << mr.getName() << " hit you for " << mr.getAttack() << " damage.\n";
                    player.reduceHealth( mr.getAttack() );
                }
        }
    
    

}

int main()
{/*
    //check C++ version:
    if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";
*/

    Player player1{ ask_for_User_name() };
    std::cout << player1;

    



    return 0;
}