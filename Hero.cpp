#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

class Race
{
private:
    char* race_name;
    void copyRace(const Race& other)
    {
        race_name = new char[strlen(other.race_name)+1];
        assert(race_name != NULL);
        strcpy(race_name, other.race_name);
    }
public:
    Race()
    {
        race_name = new char [6];
        assert(race_name != NULL);
        strcpy(race_name, "Human");
    }
    Race(char* race_name)
    {
        this->race_name = new char[strlen(race_name)+1];
        assert(this->race_name != NULL);
        if(!strcmp(race_name, "Elf") || !strcmp(race_name, "Human") || !strcmp(race_name, "Orc"))
           strcpy(this->race_name, race_name);
        else
           cout<<"Invalid race"<<endl;
    }
    ~Race()
    {
        delete [] race_name;
    }
    Race(const Race& other)
    {
        copyRace(other);
    }
    Race& operator=(const Race& other)
    {
        if(this != &other)
        {
            delete [] race_name;
            copyRace(other);
        }
        return *this;
    }
    void greetings()
    {
        if(!(strcmp(race_name, "Human")))
            cout<<"Hi, I am Human"<<endl;
        if(!strcmp(race_name, "Orc"))
            cout<<"Hi, I am Orc"<<endl;
        if(!strcmp(race_name, "Elf"))
            cout<<"Hi, I am Elf"<<endl;
    }
    void print()
    {
        cout << "class Race:\n" << race_name << "\n";
    }
};
class Hero_Type
{
private:
    char* heroType;
    void copyHeroType(const Hero_Type& other)
    {
        heroType = new char [strlen(other.heroType)+1];
        assert(heroType != NULL);
        strcpy(heroType, other.heroType);
    }
public:
    Hero_Type()
    {
        heroType = new char [7];
        assert(heroType != NULL);
        strcpy(heroType, "Hunter");
    }
    Hero_Type(char* heroType)
    {
        this->heroType = new char[strlen(heroType)+1];
        assert(this->heroType != NULL);
        if(!strcmp(heroType, "Hunter") || !strcmp(heroType, "Warrior") || !strcmp(heroType, "KindPerson"))
            strcpy(this->heroType, heroType);
        else
            cout<< "Invalid hero type"<< endl;
    }
    Hero_Type(const Hero_Type& other)
    {
        copyHeroType(other);
    }
    ~Hero_Type()
    {
        delete [] heroType;
    }
    Hero_Type& operator=(const Hero_Type& other)
    {
        if(this != &other)
        {
            delete [] heroType;
            copyHeroType(other);
        }
        return *this;
    }
    int damage()
    {
        if(!strcmp(heroType, "Hunter"))
            return 50;
        if(!strcmp(heroType, "Warrior"))
            return 75;
        if(!strcmp(heroType, "KindPerson"))
            return 0;
    }
    void print()
    {
        cout << "class Hero_Type:\n" << heroType << "\n";
    }
};
class Hero : public Race, public Hero_Type
{
private:
    char* name;
    int age,
        health;
    char logo;
    void copyHero(const Hero& other)
    {
        this->name = new char [strlen(other.name)+1];
        assert(this->name!=NULL);
        strcpy(this->name, other.name);
        this->age = other.age;
        this->health = other.health;
        this->logo = other.logo;
    }
public:

    Hero() : Race(), Hero_Type()
    {
        this->name = new char [5];
        assert(this->name!=NULL);
        strcpy(this->name, "hero");
        this->age = 1;
        this->health = 100;
        this->logo = 'T';
    }
    Hero(char* name, int age, int health, char logo, char* race_name, char* heroType) : Race(race_name), Hero_Type(heroType)
    {
        this->name = new char [strlen(name)+1];
        assert(this->name!=NULL);
        strcpy(this->name, name);
        this->age = age;
        this->health = health;
        this->logo = logo;
    }
    Hero(const Hero& other) : Race(other), Hero_Type(other)
    {
        copyHero(other);
    }
    ~Hero()
    {
        delete [] name;
    }
    Hero& operator=(const Hero& other)
    {
        if(this != &other)
        {
            Race :: operator=(other);
            Hero_Type :: operator=(other);
            delete [] name;
            copyHero(other);
        }
    }
    bool takeDamage(Hero& other)
    {
        return (health -= other.damage()) > 0;
    }
    void print()
    {
        Race :: print();
        Hero_Type :: print();
        cout << "class Hero\n";
        cout << name << " " << age << " " << health << " " << logo << '\n';
    }
};
int main()
{
    Race race1;
    race1.print();
    Race race2("Elf");
    race2.print();
    race1.greetings();
    race2.greetings();

    Hero_Type ht1;
    ht1.print();
    Hero_Type ht2("Warrior");
    ht2.print();
    cout << ht2.damage() << endl;
    cout << ht1.damage() << endl;

    Hero hero1;
    hero1.print();
    Hero hero2("Slav", 20, 100, 'S', "Elf", "KindPerson");
    hero2.print();
    hero1.takeDamage(hero2);
    hero2.takeDamage(hero1);
    hero2.print();
}

