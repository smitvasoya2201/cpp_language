#include<iostream>

using namespace std;

class Animal{
    public:
        string name;
        int age ;

    Animal(string namee,int age){
            this->name =namee;
            this->age =age;
        }

};

class Dog:public Animal{
    public:
        string breed;

    Dog(string namee,int age,string breed):Animal(namee,age){
            this->breed=breed;
        }
    
    void display(){
            cout<<name<<" "<<age<<" "<<breed;
        }

};

int main(){
   Dog d1("max",12,"lab");
   d1.display();
    return 0;

}