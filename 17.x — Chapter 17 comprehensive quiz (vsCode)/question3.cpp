#include <iostream>
#include <string>

class Creature
{
private:
    std::string m_name{};
    char m_symbol{};
    int m_hp{};
    int m_attack{};
    int m_gold_lot{};

public:
    Creature(const std::string& name, char symbol, int hp, int attack, int gold_lot)
        : m_name{ name }, m_symbol{ symbol }, m_hp{ hp }, m_attack{ attack }, m_gold_lot{ gold_lot }
    {
    }

    const std::string& getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHp() const { return m_hp; }
    int getAttack() const { return m_attack; }
    int getGold_lot() const { return m_gold_lot; }

    void reduceHealth(int hp)
    {
        m_hp -= hp;
    }

    bool isDead(int hp)
    {   
        if(hp <= 0)
        {
            return true;
        }
    }

    void addGold(int gold)
    {
        m_gold_lot += gold;
    }

};

class Player: public Creature
{
public:
    Player( const std::string& name, char symbol, int hp, int attack, int gold_lot )
        : Creature{ name, symbol, hp, attack, gold_lot }
    {
    }

};

class Monster: public Creature
{

};

int main()
{
    Creature o{ "orc", 'o', 4, 2, 10 };
    o.addGold(5);
    o.reduceHealth(1);

    std::cout << 


    return 0;
}