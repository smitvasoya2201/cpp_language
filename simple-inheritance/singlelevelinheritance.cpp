#include <iostream>

using namespace std;

class Person
{
public:
    string name;
    int age;

    Person(string names, int agee)
    {
        this->name = names;
        this->age = agee;
    }
};

class Student : public Person
{
public:
    int rollno;
    float marks;

    Student(string name, int age, int rollno, float marks) : Person(name, age)
    {
        this->rollno = rollno;
        this->marks = marks;
    }
    void display()
    {
        cout << "Name:" << name << endl
             << "Age:" << age << endl
             << "Roll No:" << rollno << endl
             << "Marks:" << marks << endl;
    }
};

int main()
{
    Student s("smit", 19, 1234, 55.554);
    s.display();
   
    return 0;
}