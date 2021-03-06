#include <iostream>
#include <string>
#include <string_view> 
#include <array>
#include <random> // for std::mt19937
#include "random.hpp" // for Random::get(min, max)
#include <limits> 
#include <utility> // for std::pair

class Potion
{
protected:

    enum class Type
    {
        type_health,
        type_strenght,
        type_posion,
        max_type,
    };

public:
    Potion() = default;

    static Type getRandomPotionType()
    {
        using Random = effolkronium::random_static;
        return static_cast<Type>( Random::get(0, (static_cast<int>(Type::max_type)-1) ) );
    }

    std::string getRandomPotionSize()
    {
        using Random = effolkronium::random_static;
        int nr{ Random::get(1, 3) };

        if(nr == 1)
        {
            return "Small";
        }
        else if(nr == 2)
        {
            return "Medium";
        }
        else if(nr == 3)
        {
            return "Large";
        }

        return "yo";
    }
};

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

class Player: public Creature, public Potion
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
        return out;
    }

    int dringPotion(Player& player)
    {
        Potion potion;
        Type type{ potion.getRandomPotionType() };
        std::string size{ potion.getRandomPotionSize() };

        if(type == Type::type_health && size == "Small")
        {
            std::cout << "You drank a Small potion of Health.\n";
            return player.m_health + 2;
        }
        else if(type == Type::type_health && size == "Medium")
        {
            std::cout << "You drank a Medium potion of Health.\n";
            return player.m_health + 2;
        }
        else if(type == Type::type_health && size == "Large")
        {
            std::cout << "You drank a Large potion of Health.\n";
            return player.m_health + 5;
        }
        else if(type == Type::type_strenght && size == "Small")
        {
            std::cout << "You drank a Small potion of Strenght.\n";
            return ++player.m_damage;
        }
        else if(type == Type::type_strenght && size == "Medium")
        {
            std::cout << "You drank a Madium potion of Strenght.\n";
            return ++player.m_damage;
        }
        else if(type == Type::type_strenght && size == "Large")
        {
            std::cout << "You drank a Large potion of Strenght.\n";
            return ++player.m_damage;
        }
        else if(type == Type::type_posion && size == "Small")
        {
            std::cout << "You drank a Small potion of Poison.\n";
            return --player.m_health;
        }
        else if(type == Type::type_posion && size == "Medium")
        {
            std::cout << "You drank a Medium potion of Poison.\n";
            return --player.m_health;
        }
        else if(type == Type::type_posion && size == "Large")
        {
            std::cout << "You drank a Large potion of Poison.\n";
            return --player.m_health;
        }

        return 0;
    }

    int getRandomPotion(Player& player)
    {
        using Random = effolkronium::random_static;
        int nr{ Random::get(1, 3) };

        char answer{};

        if(nr == 3)
        {
            std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
            std::cin >> answer;

            if( answer == 'y' || answer == 'Y' )
            {
                return player.dringPotion(player);
            }
            else
            {
                return 0;
            }

        }
        return 0;
    }
};

class Monster: public Creature
{
private:
    enum class Type
    {
        type_dragon,
        type_orc, 
        type_slime,
        max_types,
    };

public:
    Monster(const Type& type)
        : Creature{ getDefaultCreature(type) }
    {
    }

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
};

std::string ask_for_User_name()
{
    std::string name{};
    std::cout << "Enter your name: ";
    std::cin >> name;

    return name;
}

void attackMonster(Monster& mr, Player& player)
{
    char answer{};

    std::cout << "You hit the " << mr.getName() << " for " << player.getAttack() << " damage.\n";

    if(player.getAttack() >= mr.getHp())
    {
        mr.reduceHealth( player.getAttack() );
        std::cout << "You killed the " << mr.getName() << ".\n";
        player.levelUp();
        player.addGold(mr.getGold());
        
        std::cout << "You are now level " << player.getLvl() << ".\n";
        std::cout << "You found " << mr.getGold()  << " gold.\n";
        
        player.getRandomPotion(player);
        
        std::cout << "(Players info) HP: " << player.getHp() << " ATTACK: " << player.getAttack() << " GOLD: " << player.getGold() << '\n';
        std::cout << "(Monster info) HP: " << mr.getHp() << " ATTACK: " << mr.getAttack() << " GOLD: " << mr.getGold() << '\n';   
       
        return;
    }

    mr.reduceHealth( player.getAttack() );

    std::cout << "(Players info) HP: " << player.getHp() << " ATTACK: " << player.getAttack() << " GOLD: " << player.getGold() << '\n';
    std::cout << "(Monster info) HP: " << mr.getHp() << " ATTACK: " << mr.getAttack() << " GOLD: " << mr.getGold() << '\n';
}

void attackPlayer(Monster& mr, Player& player)
{
    std::cout << "The " << mr.getName() << " hit you for " << mr.getAttack()  << " damage.\n";

    if(mr.getAttack() >= player.getHp())
    {
        player.reduceHealth( mr.getAttack() );
        std::cout << "You died at level " << player.getLvl() << " and with " << player.getGold() << " gold.\n";
        std::cout << "Too bad you can???t take it with you!\n";
        return;
    }

    player.reduceHealth( mr.getAttack() );

    std::cout << "(Players info) HP: " << player.getHp() << " ATTACK: " << player.getAttack() << " GOLD: " << player.getGold() << '\n';
    std::cout << "(Monster info) HP: " << mr.getHp() << " ATTACK: " << mr.getAttack() << " GOLD: " << mr.getGold() << '\n';
}

void fightMonster(Player& player)
{
    Monster mr{ Monster::getRandomMonster() };
    std::cout << "-----------------------------------------" << '\n';
    std::cout << "You have encountered a " << mr.getName() << " (" << mr.getSymbol() << ")\n";

    while (mr.getHp() > 0 && player.getHp() > 0)
    {
        char run_or_fight{};
        
        std::cout << "-----------------------------------------" << '\n';
        std::cout << "(R)un or (F)ight: ";
        std::cin >> run_or_fight;
        
        if(run_or_fight == 'f' || run_or_fight == 'F')
        {
            attackMonster(mr, player);
            
            if(player.getAttack() <= mr.getHp() || mr.getHp() > 0)
            {
                attackPlayer(mr, player);
            }
        }
        else if(run_or_fight == 'r' || run_or_fight == 'R')
        {
            using Random = effolkronium::random_static;
            int run{ Random::get(0, 1) };

            if(run == 0)
            {
                std::cout << "You successfully fled.\n";
                return;
            }
            else if( run == 1 )
            {
                std::cout << "You failed to flee.\n";

                if(player.getHp() <= 0)
                {
                    return;
                }
                
                attackPlayer(mr, player);

                if(player.getHp() <= 0)
                {
                    return;
                }
            }
        }
    }
}

int main()
{   
    Player player1{ ask_for_User_name() };
    std::cout << player1;

    while (player1.getLvl() < 20 && player1.getHp() > 0)
    {
        fightMonster(player1);
    }

    if(player1.hasWon())
    {
        std::cout << "You hit lvl 20 you win!" << '\n';
        std::cout << "Your total gold is " << player1.getGold()  <<'\n';
    }

    return 0;
}