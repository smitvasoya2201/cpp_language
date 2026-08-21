#include <iostream>

using namespace std;

class Person
{
    public:
        string name;
        int age;
    
    Person(string name ,int age){
        this->name = name;
        this->age = age;
    }
};

class Student : public Person
{
    public:
        int rollnumber;
        string course;
        int marks;

    Student(string name, int age, int rollnumber, string course, float marks) : Person(name, age)
    {
        this->rollnumber = rollnumber;
        this->course = course;
        for(int i=0 ;i<3 ;i++){
        this->marks = marks;
        }

    }
};

class Result : public Student
{
    public:
        float result;

    Result(string name, int age, int rollnumber, string course, float marks): Student(name, age, rollnumber, course, marks)
    {
        this->result = (marks/100)*100;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << rollnumber << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Result: " << result << endl;
    }

};

int main()
{
    Result r1("Bishal", 20, 1234, "CS", 80);
    r1.display();
    return 0;
}