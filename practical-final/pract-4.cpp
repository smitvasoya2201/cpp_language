#include <iostream>

using namespace std;

class Vehical
{
private:
    string model;
    float speed;

public:
    virtual void displayDetails() = 0; // Pure virtual function

    Vehical(string model, float speed)
    {
        this->model = model;
        this->speed = speed;
    }
    void setvehical(string model, float speed)
    {
        this->model = model;
        this->speed = speed;
    }

    string getmodel()
    {
        return model;
    }
    float getspeed()
    {
        return speed;
    }
};

class car : public Vehical
{
public:
    int distance;
    void displayDetails()
    {
        cout << "Car Model: " << getmodel() << endl;
        cout << "Speed: " << getspeed() << " km/h " << endl;
        cout << " km/h,  Distance: " << distance << " km" << endl;
        cout << "Time for car: " << distance / getspeed() << " hours" << endl;
    }
    car(string model, float speed, int distance) : Vehical(model, speed)
    {
        this->distance = distance;
    }
    void calculateTime()
    {
        float time;
        time = distance / getspeed();
        cout << "Time for car: " << time << " hours" << endl;
    }
};

class bike : public Vehical
{
public:
    int distance;
    void displayDetails()
    {
        cout << "Bike Model: " << getmodel() << endl;
        cout << "Speed: " << getspeed() << endl;
        cout << " km/h, Distance: " << distance << " km" << endl;
        cout << "Time for bike: " << distance / getspeed() << " hours" << endl;
    }
    bike(string model, float speed, int distance) : Vehical(model, speed)
    {
        this->distance = distance;
    }
    void calculateTime()
    {
        float time;
        time = distance / getspeed();
        cout << "Time for bike: " << time << " hours" << endl;
    }
};

int main()
{
    Vehical *v[100];
    v[0] = new car("Toyota", 120.0, 240);
    v[1] = new car("Honda", 80.0, 240);
    v[2] = new car("BMW", 100.0, 240);
    v[3] = new bike("Yamaha", 60.0, 240);
    v[4] = new bike("Suzuki", 50.0, 240);
    v[5] = new bike("KTM", 70.0, 240);

    for (int i = 0; i < 6; i++)
    {
        cout << "Vehicle " << i + 1 << ": ";
        v[i]->displayDetails();
        cout << endl << endl;
    }

    return 0;
}