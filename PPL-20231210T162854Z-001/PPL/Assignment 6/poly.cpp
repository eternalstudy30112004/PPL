#include <iostream>
#include <cmath>

using namespace std;
class Shape{
    protected:
    virtual double area() = 0;
    virtual double perimeter() = 0;

};

class Circle :private Shape{
    private:
    int r;
    public:
    Circle(int rad):r(rad){

    }
    double area() override{
        return M_PI * r*r;
    }
    double perimeter() override{
        return M_PI * 2*r;
    }



};

class Polygon : public Shape {
private:
    int numSides;
    double sideLength;

public:
    Polygon(int sides, double length) : numSides(sides), sideLength(length) {}

    double area() override {
        double area = (numSides * sideLength * sideLength) / (4.0 * tan(M_PI / numSides));
        cout << "Area of Polygon: " << area << endl;
        return area;
    }

    double perimeter() override {
        cout << "Perimeter of Polygon: " << numSides * sideLength << endl;
        return numSides * sideLength;
    }
};

class Square:public Polygon{
    public:
    Square(int length):Polygon(4, length){}
};
class Triangle:public Polygon{
    public:
    Triangle(int length):Polygon(3, length){}
};
class Ocatagon:public Polygon{
    public:
    Ocatagon(int length):Polygon(8, length){}
};

int main()
{
Circle *circle = new Circle(5.0);
    circle->area();
    circle->perimeter();

   Triangle triangle(3.0, 4.0, 5.0);
    triangle.area();
    triangle.perimeter();

    Square square(6.0);
    square.area();
    square.perimeter();

    Polygon hexagon(6, 4.0);
    hexagon.area();
    hexagon.perimeter();

    return 0;
}
