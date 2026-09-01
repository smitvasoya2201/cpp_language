#include <iostream>

using namespace std;

class Vehical
{
private:
    string model;
    float speed;

public:
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
    car c("sxo",100.00,200);
    bike b("m10",189.00,500);

    c.calculateTime();
    b.calculateTime();
    
    return 0;
}