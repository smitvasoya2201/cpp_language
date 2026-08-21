#include <iostream>
#include <string.h>

using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

public:
    static int trainCount;
    Train()
    {
        this->trainNumber;
        this->trainName[50];
        this->source[50];
        this->destination[50];
        this->trainTime[10];
    }
    ~Train()
    {
        cout << "successful" << endl;
    }

    void inputTrainDetails(int number, char name[50], char source[50], char desti[50], char time[10])
    {
        this->trainNumber = number;
        strcpy(this->trainName, name);
        strcpy(this->source, source);
        strcpy(this->destination, desti);
        strcpy(this->trainTime, time);
    }
    void displayTrainDetails()
    {
        cout << "\n"
             << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }
    static int getTrainCount()
    {
        return trainCount;
    }
};

class RailwaySystem : public Train
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = this->getTrainCount();
    }
    void addTrain(int number, char name[50], char source[50], char desti[50], char time[10])
    {
        this->trains[trainCount].inputTrainDetails(number, name, source, desti, time);
        this->trainCount++;
    }

    void displayAllTrains()
    {
        int i;
        for (i = 0; i < this->trainCount; i++)
        {
            trains[i].displayTrainDetails();
        }
    }
    void searchTrainByNumber(int num)
    {
        totalTrains = this->getTrainCount();

        if (totalTrains >= num)
        {
            trains[num].displayTrainDetails();
        }
        else
        {
            cout << "\n"
                 << "invalid train search" << "\n";
        }
    }
};
int Train::trainCount = 0;
int main()
{
    RailwaySystem r1;
    while (1)
    {

        int choice;
        cout << "\n"
             << "--- Railway Reservation System Menu ---" << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:
            int number;
            char name[50], source[50], desti[50], time[10];
            cout << "Enter Train Number: ";
            cin >> number;
            cout << "Enter Train Name : ";
            cin >> name;
            cout << "Enter Source : ";
            cin >> source;
            cout << "Enter Destination : ";
            cin >> desti;
            cout << "Enter Train Time : ";
            cin >> time;
            cout << "add data train successfull" << endl;

            r1.addTrain(number, name, source, desti, time);

            break;
        case 2:
            r1.displayAllTrains();

            break;
        case 3:

            int num;
            cout << "Enter search train number:";
            cin >> num;
            num -= 1;

            r1.searchTrainByNumber(num);

            break;
        case 4:
            exit(0);
            cout << "Exiting the system. Goodbye!";

            break;
        default:
            cout << "Enter valid choice ";
            break;
        }
    }

    return 0;
}