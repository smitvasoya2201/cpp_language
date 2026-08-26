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
        totalVehicles++;
        this->vehicleID = vehicleID;
        this->manufacturer = manufacturer;
        this->model = model;
        this->year = year;
    }

    ~Vehicle()
    {
        cout << "deleted " << endl;
    }

    void displayVehical()
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
};

// ---------------------------------------  Aircraft class   -----------------------------------------------------------

class Aircraft : public Vehicle
{
public:
    int flightRange;
    Aircraft(int vehicleID, string manufacturer, string model, int year, int flightRange) : Vehicle(vehicleID, manufacturer, model, year)
    {
        this->flightRange = flightRange;
    }
};

// ---------------------------------------  FlyingCar class   -----------------------------------------------------------

class FlyingCar : public Car, public Aircraft
{
    FlyingCar(int vehicleID, string manufacturer, string model, int year, string fuelType, int flightRange) : Car(vehicleID, manufacturer, model, year, fuelType), Aircraft(vehicleID, manufacturer, model, year, flightRange)
    {
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
};

// ---------------------------------------  Sedan class   -----------------------------------------------------------

class Sedan : public Car
{
    Sedan(int vehicleID, string manufacturer, string model, int year, string fuelType) : Car(vehicleID, manufacturer, model, year, fuelType)
    {
    }
};

// ---------------------------------------  Suv  class   -----------------------------------------------------------

class SUV : public Car
{
    SUV(int vehicleID, string manufacturer, string model, int year, string fuelType) : Car(vehicleID, manufacturer, model, year, fuelType)
    {
    }
};

// -------------------------vehical registry class ------------------------------------------------------------------

class VehicleRegistry
{
public:
    int Vehical[100];

    void addVehicle()
    {
       
    }
    void displayingVehicles()
    {
    }
    void searchingVehicles()
    {
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
        int vehicleID, year;
        string manufacturer, model, fuelType, batteryCapacity;
        cout << endl;
        cout << "---------------------------------welcome to vehical registation-----------------------------------" << endl;
        cout << endl;
        cout << "1. Add a vehicle (of a different type)" << endl;
        cout << "2.  View all vehicles" << endl;
        cout << "3.  Search by Id" << endl;
        cout << "4.  exit" << endl
             << endl;
        cout << "enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << endl;
            int vehicleTypeChoice;
            int vehicleID, year;
            string manufacturer, model, fuelType, batteryCapacity;
            cout << " --- select vehicle type: ----- " << endl;
            cout << "1. Electric car" << endl;
            cout << "2. flyinng car" << endl;
            cout << "3. sport car" << endl;
            cout << "4. sedan" << endl;
            cout << "5. suv" << endl;

            cout << "enter your choice : ";
            cin >> vehicleTypeChoice;

            switch (vehicleTypeChoice)
            {
            case 1:

                cout << "----------------------welcome to electric car add info -----------------" << endl;
                
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
                cout << "Enter battery capacity: ";
                cin >> batteryCapacity;
               
                v.addVehicle(vehicleID  manufacturer);

                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
            break;
        }

        case 2:
            break;
        case 3:
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    return 0;
}