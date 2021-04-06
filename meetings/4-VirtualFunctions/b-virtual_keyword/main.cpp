#include <iostream>
#include <string>
#include "animals.hpp"
#include <stdexcept>
#include <vector>

using namespace std;

void report(Cat &cat){
    cout << cat.getName() << " says " << cat.speak() << '\n';
}
 
void report(Dog &dog){
    cout << dog.getName() << " says " << dog.speak() << '\n';
}

void report(Animal &animal){
    cout << animal.getName() << " says " << animal.speak() << '\n';
}


class AnimalFactory{
public:
    Animal* generate_new(string animal, string name){

        if (animal == "cat"){
            Animal* pAnimal = new Cat(name);
            return pAnimal;
            }

        else if (animal == "dog"){
            Animal* pAnimal = new Dog(name);
            return pAnimal;
            }
        else
            throw std::runtime_error( "Wrong type of animal provided...FATAL" );
        
    }

};



int main(){
    

//    Cat cat("Tom");
//    Dog dog("Pluto");

  //  report(cat);
  //  report(dog);

 //   Animal &rCat{cat};

 //   report(rCat);

/*
    Cat fred{ "Fred" };
    Cat misty{ "Misty" };
    Cat zeke{ "Zeke" };
 
    Dog garbo{ "Garbo" };
    Dog pooky{ "Pooky" };
    Dog truffle{ "Truffle" };
 
    Animal *animals[]{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };
 
    for (auto *animal : animals)
        cout << animal->getName() << " says " << animal->speak() << '\n';
*/

    int N_animals;
    cout << "How many animals do you want to generate? " << endl;
    cin >> N_animals;
    
    vector<Animal*> animals;
    AnimalFactory Factory;
    for (int i = 0 ; i < N_animals ; ++i){
        string animal_type;
        string animal_name;
        cout << endl << "Provide the type of the " << i + 1 << "-th animal (cat/dog): ";
        cin >> animal_type;
        cout << endl << "Provide the name of the " << i + 1 << "-th animal: ";
        cin >> animal_name;
        Animal* new_animal = Factory.generate_new(animal_type, animal_name);
        animals.push_back(new_animal);
    }

    for (int i = 0 ; i < N_animals ; ++i){
        report(*animals[i]);
    }
    
    

}