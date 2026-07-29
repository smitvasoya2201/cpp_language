#include<iostream>
using namespace std;

int main(){
    string fname, lname ;
    int age ,maths ,science ,english ;
    cout << "enter first name : " ;
    cin >> fname;
    cout << endl;
    cout << "enter last name : " ;
    cin >> lname ;
    cout << endl;
    cout << "your age is :  " ;
    cin >> age;
    cout << endl;
    cout << "first name : " <<fname << endl << "last name : "<< lname << endl <<"your age  is : " <<age <<endl ;
    cout << "enter marks of maths science and english : " ;
    cin >> maths >> science >> english ;
    cout <<" your percantage is : " <<(float)(maths + science + english)/3;
 

}