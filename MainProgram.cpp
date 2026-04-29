#include <iostream>
#include <string>
#include <cmath>

class Point {
private:
    double x;
    double y;
public:
    Point(double x, double y) : x(x), y(y) {}           // TODO 1 fixed

    double getX() const { return x; }                    // TODO 2 fixed
    double getY() const { return y; }                    // TODO 3 fixed

    void display() const {                               // TODO 4 fixed
        std::cout << "(" << x << ", " << y << ")";
    }

    friend class Rectangle;                              // TODO 5 fixed
};

class Rectangle {
private:
    Point topLeft;
    Point bottomRight;
public:
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {}       // TODO 6 fixed

    double getWidth() const {                            // TODO 7 fixed
        return std::abs(bottomRight.x - topLeft.x);
    }
    double getHeight() const {                           // TODO 8 fixed
        return std::abs(bottomRight.y - topLeft.y);
    }
    double getArea() const {                             // TODO 9 fixed
        return getWidth() * getHeight();
    }

    void display() const {                               // TODO 10 fixed
        topLeft.display();
        std::cout << " to ";
        bottomRight.display();
        std::cout << " [" << getWidth() << "x" << getHeight() << "]";
    }

    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2); // TODO 11 fixed
};

bool isSameSize(const Rectangle& r1, const Rectangle& r2) { // TODO 12 fixed
    return r1.getArea() == r2.getArea();
}

class ConstDemo {
private:
    int value;
public:
    ConstDemo(int v) : value(v) {}                       // TODO 13 fixed

    int getValue() const { return value; }               // TODO 14 fixed

    void doubleValue() { value *= 2; }                   // TODO 15 fixed

    int constGetDouble() const { return value * 2; }     // TODO 16 fixed
};

int main() {
    Point p(3.0, 4.0);                                   // TODO 17
    std::cout << "Point: ";
    p.display();
    std::cout << std::endl;

    Rectangle r1(0, 0, 5, 3);                            // TODO 18
    std::cout << "Rectangle r1: ";
    r1.display();
    std::cout << std::endl;

    std::cout << "Width: " << r1.getWidth()              // TODO 19
              << " Height: " << r1.getHeight()
              << " Area: " << r1.getArea() << std::endl;

    Rectangle r2(1, 1, 4, 6);                            // TODO 20
    std::cout << "Same size? "
              << (isSameSize(r1, r2) ? "yes" : "no") << std::endl;

    ConstDemo cd(5);                                     // TODO 21
    std::cout << "Value: " << cd.getValue() << std::endl;
    std::cout << "Const double: " << cd.constGetDouble() << std::endl;
    cd.doubleValue();
    std::cout << "After doubleValue: " << cd.getValue() << std::endl;

    return 0;
}
