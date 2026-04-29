// ============================================================
// Lab: More Details about Classes
// Course: Object-Oriented Programming (C++)
// Level: 2nd Year Engineering
// Duration: 60 minutes
// ============================================================

#include <iostream>
#include <string>

// Forward Declaration
class Rectangle;

// ============================================================
// CLASS DEFINITIONS
// ============================================================

class Point {
private:
    double x;
    double y;
public:
    // TODO 1
    Point(double x, double y) : x(x), y(y) {}

    // TODO 2
    double getX() const { return x; }

    // TODO 3
    double getY() const { return y; }

    // TODO 4
    void display() const { std::cout << "(" << x << ", " << y << ")"; }

    // TODO 5
    friend class Rectangle;
};

class Rectangle {
private:
    Point topLeft;
    Point bottomRight;
public:
    // TODO 6
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {}

    // TODO 7
    double getWidth() const { return bottomRight.x - topLeft.x; }

    // TODO 8
    double getHeight() const { return topLeft.y - bottomRight.y; }

    // TODO 9
    double getArea() const { return getWidth() * getHeight(); }

    // TODO 10
    void display() const {
        std::cout << "Rectangle: ";
        topLeft.display();
        std::cout << " to ";
        bottomRight.display();
        std::cout << std::endl;
    }

    // TODO 11
    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};

// TODO 12
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return (r1.getWidth() == r2.getWidth() &&
            r1.getHeight() == r2.getHeight());
}

class ConstDemo {
private:
    int value;
public:
    // TODO 13
    ConstDemo(int v) : value(v) {}

    // TODO 14
    int getValue() const { return value; }

    // TODO 15
    void doubleValue() { value *= 2; }

    // TODO 16
    int constGetDouble() const { return value * 2; }
};

// ============================================================
// MAIN
// ============================================================
int main() {
    // TODO 17-21

    // Rectangle test
    Rectangle r1(0, 10, 5, 0);
    Rectangle r2(0, 10, 5, 0);

    std::cout << "Rectangle 1: ";
    r1.display();
    std::cout << "Area: " << r1.getArea() << std::endl;

    std::cout << "Rectangle 2: ";
    r2.display();
    std::cout << "Area: " << r2.getArea() << std::endl;

    if (isSameSize(r1, r2)) {
        std::cout << "Result: Same size (width & height match)" << std::endl;
    } else {
        std::cout << "Result: Different size" << std::endl;
    }

    std::cout << "------------------------" << std::endl;

    // ConstDemo test
    const ConstDemo cd(50);
    std::cout << "Const value: " << cd.getValue() << std::endl;
    std::cout << "Const double: " << cd.constGetDouble() << std::endl;

    // Non-const usage
    ConstDemo d(10);
    std::cout << "Before doubleValue: " << d.getValue() << std::endl;
    d.doubleValue();
    std::cout << "After doubleValue: " << d.getValue() << std::endl;

    return 0;
}
