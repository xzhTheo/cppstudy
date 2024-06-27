#include <iostream>
using namespace std;
class Shape
{
public:
    virtual double getArea() = 0; // 纯虚函数
};

class Circle : public Shape
{
public:
    Circle(double r) : radius(r) {}
    double getArea()
    {
        return 3.14 * radius * radius;
    }

private:
    double radius;
};

class Rectangle : public Shape
{
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea()
    {
        return width * height;
    }

private:
    double width;
    double height;
};

class triangle : public Shape
{
public:
    triangle() {}

private:
    double width;
    double height;
};

int main()
{
    // Shape s; 不能直接实例化
    Circle c(5);
    Rectangle r(4, 6);
    triangle t();
    cout << "Circle area: " << c.getArea() << endl;
    cout << "Rectangle area: " << r.getArea() << endl;
    return 0;
}