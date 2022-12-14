#include <iostream>
#include <string>
using namespace std;

class Fish
{

public:
    std::string name, preferredFood;
    int age, species;
    double size, neededSpace;
    bool isAggressive;

    void init(string name, int age, int species, double size, string preferredFood, bool isAggressive, double neededSpace)
    {
        this->name = name;
        this->age = age;
        this->species = species;
        this->size = size;
        this->preferredFood = preferredFood;
        this->isAggressive = isAggressive;
        this->neededSpace = neededSpace;
    }
};

class Aquarium
{
private:
    double totalVolume;
    int freeSpace;
    Fish fish[3];
    // Fish arr[];

public:
    Aquarium(double totalVolume)
    {
        this->totalVolume = totalVolume;
        this->freeSpace = totalVolume;
    }

    void addFish(Fish f[8])
    {
        for (int i = 0; i < 3; i++)
        {
            int r1 = 0;
            r1 =rand() % 8;
            this->fish[i] = f[r1];
            this->freeSpace = this->freeSpace - f[r1].neededSpace;

        }
    }

    Fish *getAllFish()
    {
        return this->fish;
    }

    double getFreeSpace()
    {
        return this->freeSpace;
    }

    double getTotalVolume()
    {
        return this->totalVolume;
    }
};

int main()
{

    Fish fish[8];
    fish[0].init("fName1", 1, 1, 2.3, "meet", false, 0.3);
    fish[2].init("fName2", 3, 4, 5.3, "meet", true, 2.3);
    fish[3].init("fName3", 1, 2, 8.3, "meet", false, 2.3);
    fish[1].init("fName4", 1, 5, 4.3, "meet", true, 3.3);
    fish[4].init("fName5", 1, 3, 1.3, "meet", false, 1.3);
    fish[5].init("fName6", 1, 3, 1.3, "meet", false, 4.3);
    fish[6].init("fName7", 1, 3, 1.3, "meet", true, 5.3);
    fish[7].init("fName8", 1, 3, 1.3, "meet", false, 3.3);

    Aquarium a(33.5);

    a.addFish(fish);
    double fs = a.getFreeSpace();

    cout << "free space - " + std::to_string(fs) + " Aquarium space - " + std::to_string(a.getTotalVolume()) << endl;

    Fish* f = a.getAllFish();

    cout << "List of fish in Aquarium:" << endl;
    for (int ii = 0; ii < 5; ii++)
    {
        cout << f[ii].name << endl;
    }
}
