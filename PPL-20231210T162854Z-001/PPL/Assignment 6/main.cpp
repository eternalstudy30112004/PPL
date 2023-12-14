#include <iostream>
#include <cmath>
using namespace std;
class Shape {
public:
    virtual void CalculateArea() = 0;
    virtual void CalculatePerimeter() = 0;
};

class Circle : public Shape {
private:    
    double radius;

public:
    Circle(double r) : radius(r) {}

    void CalculateArea() override {
        cout << "Area of Circle: " << 3.14159 * radius * radius << endl;
    }

    void CalculatePerimeter() override {
        cout << "Perimeter of Circle: " << 2 * 3.14159 * radius << endl;
    }
};

class Triangle : public Shape {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    void CalculateArea() override {
        double s = (side1 + side2 + side3) / 2.0;
        cout << "Area of Triangle: " << sqrt(s * (s - side1) * (s - side2) * (s - side3)) << endl;
    }

    void CalculatePerimeter() override {
        cout << "Perimeter of Triangle: " << side1 + side2 + side3 << endl;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    void CalculateArea() override {
        cout << "Area of Square: " << side * side << endl;
    }

    void CalculatePerimeter() override {
        cout << "Perimeter of Square: " << 4 * side << endl;
    }
};

class Polygon : public Shape {
private:
    int numSides;
    double sideLength;

public:
    Polygon(int sides, double length) : numSides(sides), sideLength(length) {}

    void CalculateArea() override {
        double area = (numSides * sideLength * sideLength) / (4.0 * tan(M_PI / numSides));
        cout << "Area of Polygon: " << area << endl;
    }

    void CalculatePerimeter() override {
        cout << "Perimeter of Polygon: " << numSides * sideLength << endl;
    }
};

class Ocatagon:public Polygon{
    private:
    int side;
    public:
    Ocatagon(int length):side(length) ,Polygon(8, length){

    }
};

int main() {
    Circle *circle = new Circle(5.0);
    circle->CalculateArea();
    circle->CalculatePerimeter();

   Triangle triangle(3.0, 4.0, 5.0);
    triangle.CalculateArea();
    triangle.CalculatePerimeter();

    Square square(6.0);
    square.CalculateArea();
    square.CalculatePerimeter();

    Polygon hexagon(6, 4.0);
    hexagon.CalculateArea();
    hexagon.CalculatePerimeter();

    return 0;
}
