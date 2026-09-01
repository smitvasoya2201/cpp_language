#include <iostream>

using namespace std;

class Shape
{
public:
    virtual void calculateArea() = 0;
    virtual void draw() = 0;
};

class Circle : public Shape
{   public:
        float radius;
        float area;
    Circle(float r)
    {
        this->radius = r;
    }
     void calculateArea()
    {
        area = 3.14 * radius * radius;
        cout << "Area: " << area << endl;
    }
     void draw()
    {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape
{   public:
        float length;
        float width;
        float area;
    Rectangle(float l, float w)
    {
        this->length = l;
        this->width = w;
    }
     void calculateArea()    
    {
       cout << "Length: " << length << " Width: " << width << endl;
       cout << "Area: " << length * width << endl;
    }
     void draw()
    {
        cout << "Drawing Rectangle" << endl;
    }
};

int main()
{
    Shape *shapes[100];
    shapes[0] = new Circle(5);
    shapes[1] = new Circle(10);
    shapes[2] = new Rectangle(5, 10); 
    shapes[3] = new Rectangle(10, 20);  

    for (int i = 0; i < 4; i++){

        shapes[i]->calculateArea();
        shapes[i]->draw();
        cout << endl << endl ;
    }
    return 0;
}