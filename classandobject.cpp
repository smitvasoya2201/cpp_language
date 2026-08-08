#include <iostream>
using namespace std;

class Student
{

public:
    string lname;
    int id, age;
    string fname;

    Student(int data1, int data2, string data3, string data4)
    {
        id = data1;
        fname = data3;
        age = data2;
        lname = data4;
    }
};

int main()
{
    Student s1 = Student(1, 20, "John", "Doe");
    Student s2 = Student(2, 22, "Jane", "Smith");
    Student s3 = Student(3, 21, "Alice", "Johnson");
    cout << "firstname : " << s1.fname << endl
         << " lastname : " << s1.lname << endl
         << " age : " << s1.age << endl
         << " id : " << s1.id << endl
         << endl
         << endl;
    cout << "firstname : " << s2.fname << endl
         << " lastname : " << s2.lname << endl
         << " age : " << s2.age << endl
         << " id : " << s2.id << endl;
    cout << "firstname : " << s3.fname << endl
         << " lastname : " << s3.lname << endl
         << " age : " << s3.age << endl
         << " id : " << s3.id << endl;

    return 0;
}