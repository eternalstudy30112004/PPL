#include <iostream>
#include <string>

using namespace std;

class Animal
{

private:
    string name;
    string species;
    int age;
    string type;

public:
    Animal() : type("domestic"),age(0),species("default"),name("d")
    {


        cout << "contructor for Animal" << endl;
    }
    Animal(string n, string s, int a):(n,s,a,"domestic"){}
    
    Animal(string n, string s, int a, string t)
    {
        name = n;
        species = s;
        age = a;
        type = t;
    }
    ~Animal()
    {
        cout << "Killing Animal" << endl;
    }
    void read_data()
    {

        cout << "Name : " << endl;
        cin >> name;
        cout << "Species : " << endl;
        cin >> species;
        cout << "age : " << endl;
        cin >> age;
        cout << "type : " << endl;
        cin >> type;
    }
    void print_data()
    {
        cout << "" << endl;
        cout << "Name : " ;
        cout << name;
        cout << "Species : " ;
        cout << species;
        cout << "age : " ;
        cout << age;
        cout << "type : " ;
        cout << type;
    }
};

int main()
{
    Animal cat = Animal();
    cat.print_data();
    Animal dog("Tommy", "dog", 4);
    dog.print_data();
    return 0;
}
