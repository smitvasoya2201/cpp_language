#include<iostream>

using namespace std;

class Student{
    public:
        int marks[3];
    
    Student(int marks, int marks2, int marks3){
        this->marks[0] = marks;
        this->marks[1] = marks2;
        this->marks[2] = marks3;
    }

};
class Sports{
    public:
        int mark;

    Sports(int mark){
        this->mark = mark;
    }

};

class Result:public Student,public Sports{
    public:
        int total;

    
    Result(int m1,int m2,int m3,int mark):Student(m1,m2,m3),Sports(mark){
            total = m1+m2+m3+mark;
        }
        void display(){
            cout<<"Total is ";
            cout<<total;
        }


};

int main(){
    Result r1(90,80,70,50);
    r1.display();

    return 0;
}