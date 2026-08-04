#include <iostream>

using namespace std;

int main()
{
    int mark1;
    int mark2;
    int mark3;
    int mark4;
    int mark5;
    cout << "enter marks of 1 subjects : ";
    cin >> mark1;
    cout << "enter marks of 2 subjects : " ;
    cin >> mark2;
    cout << "enter marks of 3 subjects : " ;
    cin >> mark3;
    cout << "enter marks of 4 subjects : " ;
    cin >> mark4;
    cout << "enter marks of 5 subjects : " ;
    cin >> mark5;
    int avg=  ( mark1 + mark2 + mark3 + mark4 + mark5 )/5;
    cout << "your average is : " << avg << endl;
    
    if(avg >=95){
        cout<< "A+ grades" << endl;

    }else if(avg >=80 && avg <95){

        cout<< "b grades" << endl;
    }else if(avg >=65 && avg <80){
        cout<< "c grades" << endl;

    }else if(avg >=35 && avg <65){
        cout<< "d grades" << endl;  
    }else{
        cout<< "fail" << endl;
    }
    return 0;
}