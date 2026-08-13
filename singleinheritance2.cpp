#include<iostream>

using namespace std;

class Employee{

    public:
    string name;
    int salary;

    Employee(string fname , int fsalary){
        name = fname;
        salary =fsalary;
    }

};

class Manager : public Employee{

    public:
    string department;
    int bonus;

    Manager(string fname ,int fsalary ,string department ,int bonus) : Employee(fname ,fsalary){
        this->department = department;
        this->bonus = bonus;
    }

    void totalsalary(){
        int totalsalary = bonus +salary;
        cout << "department : " << department << endl ;
        cout << "manager name : " << name << endl;
        cout << "manager salary : " << salary << endl;
        cout << "manager bonus : " << bonus << endl;
        cout << "manager total salary :  " << totalsalary <<endl;
    }
};

int main(){
    
    Manager m1("harry",2000,"coding",1005000);
    m1.totalsalary();
    return 0;
}
