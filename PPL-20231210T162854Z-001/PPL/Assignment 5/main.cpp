#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
    string name;
    int age;
    string species;

public:
    Animal(string n, int a, string s) : name(n), age(a), species(s) {}
    Animal() : name(""), age(0), species("") {}
    ~Animal() {
        cout << "Destructor called for " << name << endl;
    }

    void read_data() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter species: ";
        cin >> species;
    }

    void print_animal() {
        cout << "Name: " << name << ", Age: " << age << ", Species: " << species << endl;
    }
};

int main() {
    Animal *cat = new Animal();
    Animal *dog = new Animal();
    Animal elephant("Babar", 8, "Elephant");
    Animal fish("Goldie", 2, "Fish");

    cat->read_data();
    dog->read_data();

    cout << endl << "Animal Information by Input:" << endl;
    cat->print_animal();
    dog->print_animal();

    cout << endl << "Existing Animal Information :" << endl;
    elephant.print_animal();
    fish.print_animal();
    
    delete cat;
    delete dog;

    return 0;
}
