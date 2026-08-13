#include <iostream>

using namespace std;

class Vehical {
    public :
        string brand;
        int speed;

    Vehical(string brand , int age){
        this->brand = brand;
        this->speed = speed;
    }
};

class Car : public Vehical{
    public :
        string model;
        int price;
    
    Car(string brand , int speed ,string mode ,int price) :  Vehical(brand ,speed){
        this ->model = mode;
        this ->price = price;

    }
    void Display(){
        cout << brand << endl;
        cout << speed << endl;
        cout << model << endl;
        cout << price << endl;
    }


};

int main(){
    Car c1("bmw" , 450 , "sxo" , 2000000);
    c1.Display();

    return 0;
}