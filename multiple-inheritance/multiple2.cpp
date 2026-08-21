#include<iostream>

using namespace std;

class Acedamy{
    public :
        int marks[3];

    Acedamy(int m1,int m2,int m3){
        this->marks[0] = m1;
        this->marks[1] = m2;
        this->marks[2] = m3;
    }


};

class Sport{
     public :
        int mark;

    Sport(int mark){
        this->mark = mark;

    }


};

class Student:public Acedamy,public Sport{
     public :
        int total;

     Student(int m1,int m2,int m3,int m4):Acedamy(m1,m2,m3),Sport(m4){
      total= m1+m2+m3+m4;
     }
     void display(){
         cout<< this->total <<endl;
     }


};

int main(){
    Student s1(90,80,85,95);
    s1.display();

}