#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
// --------------------------------------  vehical  base class   ------------------------------------------------------

class Vehicle
{
public:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

    static int totalVehicles;

public:
    Vehicle(int vehicleID, string manufacturer, string model, int year) // constructore
    {
        this->vehicleID = vehicleID;
        this->manufacturer = manufacturer;
        this->model = model;
        this->year = year;
        totalVehicles++;
    }

    ~Vehicle()
    {
        cout << "deleted " << endl;
    }

    virtual void display()
    {
        cout << "vehicle ID: " << vehicleID << endl;
        cout << "manufacturer: " << manufacturer << endl;
        cout << "model: " << model << endl;
        cout << "year: " << year << endl;
    }
};

// -------------------------------------- Car  class  --- -----------------------------------------------------------

class Car : public Vehicle
{
public:
    string fuelType;

    Car(int vehicleID, string manufacturer, string model, int year, string fuelType) : Vehicle(vehicleID, manufacturer, model, year)
    {

        this->fuelType = fuelType;
    }
    void display()
    {
        Vehicle::display();
        cout << "fuel type: " << fuelType << endl;
    }
};

// -------------------------------------- ElectricCar  class   -----------------------------------------------------------

class ElectricCar : public Car
{
public:
    string batteryCapacity;
    ElectricCar(int vehicleID, string manufacturer, string model, int year, string fuelType, string batteryCapacity) : Car(vehicleID, manufacturer, model, year, fuelType)
    {

        this->batteryCapacity = batteryCapacity;
    }
    void display() override
    {
        Car::display();
        cout << "battery capacity: " << batteryCapacity << endl;
    }
};

// ---------------------------------------  Aircraft class   -----------------------------------------------------------

class Aircraft : public Car
{
public:
    int flightRange;
    Aircraft(int vehicleID, string manufacturer, string model, int year, string fuelType, int flightRange) : Car(vehicleID, manufacturer, model, year, fuelType)
    {
        this->flightRange = flightRange;
    }
    void display()
    {
        Car::display();
        cout << "flight range: " << flightRange << endl;
    }
};

// ---------------------------------------  FlyingCar class   -----------------------------------------------------------

class FlyingCar : public Aircraft
{
public:
    FlyingCar(int vehicleID, string manufacturer, string model, int year, string fuelType, int flightRange) : Aircraft(vehicleID, manufacturer, model, year, fuelType, flightRange)
    {
    }
    void display()
    {
        Aircraft::display();
    }
};

// ---------------------------------------  SportsCar  class   -----------------------------------------------------------

class SportsCar : public ElectricCar
{
public:
    int topSpeed;
    SportsCar(int vehicleID, string manufacturer, string model, int year, string fuelType, string batteryCapacity, int topSpeed) : ElectricCar(vehicleID, manufacturer, model, year, fuelType, batteryCapacity)
    {

        this->topSpeed = topSpeed;
    }
    void display()
    {
        ElectricCar::display();
        cout << "top speed: " << topSpeed << endl;
    }
};

// ---------------------------------------  Sedan class   -----------------------------------------------------------

class Sedan : public Car
{
public:
    Sedan(int vehicleID, string manufacturer, string model, int year, string fuelType) : Car(vehicleID, manufacturer, model, year, fuelType)
    {
    }
    void display()
    {
        Car::display();
    }
};

// ---------------------------------------  Suv  class   -----------------------------------------------------------

class SUV : public Car
{
public:
    SUV(int vehicleID, string manufacturer, string model, int year, string fuelType) : Car(vehicleID, manufacturer, model, year, fuelType)
    {
    }
    void display()
    {
        Car::display();
    }
};

// -------------------------vehical registry class ------------------------------------------------------------------

class VehicleRegistry
{
public:
    int count = 0;
    Vehicle *vehicles[100];

    VehicleRegistry()
    {
        for (int i = 0; i < 100; i++)
        {
            vehicles[i] = NULL;
        }
    }
    void addVehicle()
    {
        int vehicleID, year, flightRange, topSpeed, chice;
        string manufacturer, model, fuelType, batteryCapacity;
        cout << endl;
        cout << "Enter type of vehicle: " << endl;
        cout << "1. Electric Car" << endl;
        cout << "2. Aircraft" << endl;
        cout << "3. Flying Car" << endl;
        cout << "4. Sports Car" << endl;
        cout << "5. Sedan" << endl;
        cout << "6. SUV" << endl;
        cout << "7. CAR" << endl;

        cout << "Enter your choice: ";
        cin >> chice;
        cout << "Enter vehicle ID: ";
        cin >> vehicleID;
        cout << "Enter manufacturer: ";
        cin >> manufacturer;
        cout << "Enter model: ";
        cin >> model;
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter fuel type: ";
        cin >> fuelType;
        switch (chice)
        {
            if (count >= 100)
            {
                cout << "Vehicle registry is full. Cannot add more vehicles." << endl;
                return;
            }
        case 1:
            cout << "Enter battery capacity: ";
            cin >> batteryCapacity;
            vehicles[count] = new ElectricCar(vehicleID, manufacturer, model, year, fuelType, batteryCapacity);
            cout << "Electric Car added successfully." << endl
                 << endl;
            count++;
            break;
        case 2:
            cout << "Enter flight range: ";
            cin >> flightRange;
            vehicles[count] = new Aircraft(vehicleID, manufacturer, model, year, fuelType, flightRange);
            cout << "Aircraft added successfully." << endl
                 << endl;
            count++;
            break;
        case 3:
            cout << "Enter flight range: ";
            cin >> flightRange;
            vehicles[count] = new FlyingCar(vehicleID, manufacturer, model, year, fuelType, flightRange);
            cout << "Flying Car added successfully." << endl
                 << endl;
            count++;
            break;
        case 4:
            cout << "Enter top speed: ";
            cin >> topSpeed;
            vehicles[count] = new SportsCar(vehicleID, manufacturer, model, year, fuelType, batteryCapacity, topSpeed);
            cout << "Sports Car added successfully." << endl
                 << endl;
            count++;
            break;
        case 5:
            vehicles[count] = new Sedan(vehicleID, manufacturer, model, year, fuelType);
            cout << "Sedan added successfully." << endl
                 << endl;
            count++;
            break;
        case 6:
            vehicles[count] = new SUV(vehicleID, manufacturer, model, year, fuelType);
            cout << "SUV added successfully." << endl
                 << endl;
            count++;
            break;
        case 7:
            vehicles[count] = new Car(vehicleID, manufacturer, model, year, fuelType);
            cout << "Car added successfully." << endl
                 << endl;
            count++;
            break;
        }
    }
    void displayingVehicles()
    {
        for (int i = 0; i < count; i++)
        {
            cout << "Vehicle " << i + 1 << ":" << endl;
            vehicles[i]->display();
            cout << endl
                 << endl;
        }
    }
    void searchingVehicles()
    {
        for (int i = 0; i < count; i++)
        {
            int v;
            cout << "Enter vehicle ID to search: ";
            cin >> v;
            if (vehicles[i]->vehicleID == v)
            {
                cout << "Vehicle found:" << endl;
                vehicles[i]->display();

                return;
            }
        }
        cout << "Vehicle not found." << endl;
    }
};
int Vehicle::totalVehicles = 0;

// -------------------------------------------------main function ------------------------------------------------------

int main()
{
    VehicleRegistry v;
    while (true)
    {
        int choice;
        cout << "1. Add Vehicle" << endl;
        cout << "2. Display Vehicles" << endl;
        cout << "3. Search Vehicles" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            v.addVehicle();
            break;
        case 2:
            v.displayingVehicles();
            break;
        case 3:
            v.searchingVehicles();
            break;
        case 4:
            exit(0);
        }
    }

    return 0;
}