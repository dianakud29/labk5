#include <iostream>
#include <string>
using namespace std;

class Fish{

public:
    string name, preferred_food, species;
    int age;
    double size, needed_space;
    bool is_aggressive;

    void init(string name, int age, string species, double size, string preferred_food, bool is_aggressive, double needed_space){
        this->name = name;
        this->age = age;
        this->species = species;
        this->size = size;
        this->preferred_food = preferred_food;
        this->is_aggressive = is_aggressive;
        this->needed_space = needed_space;
    }
};

class Aquarium{
private:
    double total_volume;
    int free_space;
    Fish fish[3];
    // Fish arr[];

public:
    Aquarium(double total_volume)
    {
        this->total_volume = total_volume;
        this->free_space = total_volume;
    }

    void addFish(Fish f[8]){
        for (int i = 0; i < 3; i++){
            int r1 = 0;
            r1 =rand() % 8;
            this->fish[i] = f[r1];
            this->free_space = this->free_space - f[r1].needed_space;

        }
    }

    Fish *get_all_fish(){
        return this->fish;
    }

    double get_free_space(){
        return this->free_space;
    }

    double get_total_volume(){
        return this->total_volume;
    }
};

int main(){

    Fish fish[8];
    fish[0].init("fName1", 1, 1, 2.3, "meet", false, 0.3);
    fish[2].init("fName2", 3, 4, 5.3, "meet", true, 2.3);
    fish[3].init("fName3", 1, 2, 8.3, "meet", false, 2.3);
    fish[1].init("fName4", 1, 5, 4.3, "meet", true, 3.3);
    fish[4].init("fName5", 1, 3, 1.3, "meet", false, 1.3);
    fish[5].init("fName6", 1, 3, 1.3, "meet", false, 4.3);
    fish[6].init("fName7", 1, 3, 1.3, "meet", true, 5.3);
    fish[7].init("fName8", 1, 3, 1.3, "meet", false, 3.3);

    Aquarium first_aquarium(33.5);

    first_aquarium.addFish(fish);
    double fs = first_aquarium.get_free_space();

    cout << "free space - " + to_string(fs) + " Aquarium space - " + to_string(a.get_total_volume()) << endl;

    Fish* f = first_aquarium.get_all_fish();

    cout << "List of fish in Aquarium:" << endl;
    for (int ii = 0; ii < 5; ii++){
        cout << f[ii].name << endl;
    }
}
