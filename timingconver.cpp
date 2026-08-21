#include <iostream>

using namespace std;

class TimeConveter 
{    
    public :
    int hours, minutes, seconds;

    void SecondtoHours()
    {
        hours = seconds / 3600;
        minutes =(seconds % 3600)/60;
        seconds = (seconds % 3600) % 60;
        cout << "HH:MM:SS => " << hours << ":" << minutes << ":" << seconds <<endl ;
    }
    void HourstoSeconds()
    {
        seconds = (hours * 3600) + (minutes * 60) + seconds;
        cout << "Total seconds : " << seconds <<endl;
    }
};

int main()
{
    TimeConveter t1;
    int choice;
    cout << " 1.(From seconds to HH:MM:SS)" << endl
         << "2.(From HH:MM:SS to seconds)" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter the total seconds : ";
        cin >> t1.seconds;
        t1.SecondtoHours();
        break;
    case 2:
        cout << "Enter the Hours : ";
        cin >> t1.hours;
        cout << "Enter the Minutes : ";
        cin >> t1.minutes;
        cout << "Enter the Seconds : ";
        cin >> t1.seconds;
        t1.HourstoSeconds();
        break;
    default:
        cout << "Invalid Choice !" << endl;
        break;
    }

    return 0;
}
