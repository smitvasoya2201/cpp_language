#include<iostream>

using namespace std;

class Animal{ 
    public:
        void sleep() {
            cout << "Animal is sleeping" << endl;
        }
};

class Dog:public Animal{
    public:
        void bark() {
            cout << "dog bites" << endl;
        }
};
class Cat:public Animal{
    public:
        void meow() {
            cout << "cat says meow" << endl;
        }
};
 


class Cow:public Animal{
    public:
        void moo() {
            cout << "cow says mooo" << endl;
        }
};

int main(){
    Dog d1;
    d1.sleep();
    d1.bark();

    Cat c1;
    c1.sleep();
    c1.meow();

    Cow co1;
    co1.sleep();
    co1.moo();


    return 0;
}