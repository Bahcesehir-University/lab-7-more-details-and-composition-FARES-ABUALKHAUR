// ============================================================
// Lab: More Details about Classes
// Course: Object-Oriented Programming (C++)
// Level: 2nd Year Engineering
// Duration: 60 minutes
// ============================================================

#include <iostream>
#include <string>

// ============================================================
// CLASS DEFINITIONS
// ============================================================

class Rectangle;

class Point {
private:
    double x;
    double y;
public:
    // TODO 1: Constructor with member initializer list (double x, double y)
    Point(double x, double y) : x(x), y(y) {}

    // TODO 2: const getter for x
    double getX() const { return x; }

    // TODO 3: const getter for y
    double getY() const { return y; }

    // TODO 4: const display()
    void display() const { std::cout << "(" << x << ", " << y << ")"; }

    // TODO 5: declare Rectangle as friend class
    friend class Rectangle;
};


class Rectangle {
private:
    Point topLeft;
    Point bottomRight;
public:
    // TODO 6: constructor with member initializer list
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {}

    // TODO 7: const getWidth()
    double getWidth() const { return bottomRight.x - topLeft.x; }

    // TODO 8: const getHeight()
    double getHeight() const { return topLeft.y - bottomRight.y; }

    // TODO 9: const getArea()
    double getArea() const { return getWidth() * getHeight(); }

    // TODO 10: const display()
    void display() const {
        std::cout << "TopLeft: ";
        topLeft.display();
        std::cout << ", BottomRight: ";
        bottomRight.display();
        std::cout << ", Width: " << getWidth()
                  << ", Height: " << getHeight()
                  << ", Area: " << getArea() << std::endl;
    }

    // TODO 11: declare isSameSize as friend function
    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};


// TODO 12: implement isSameSize
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return (r1.getWidth() == r2.getWidth()) &&
           (r1.getHeight() == r2.getHeight());
}


class ConstDemo {
private:
    int value;
public:
    // TODO 13: constructor with member initializer list
    ConstDemo(int v) : value(v) {}

    // TODO 14: const getValue()
    int getValue() const { return value; }

    // TODO 15: NON-const doubleValue() — multiplies value by 2
    void doubleValue() { value *= 2; }

    // TODO 16: const constGetDouble() — returns value * 2 without modifying
    int constGetDouble() const { return value * 2; }
};


// ============================================================
// MAIN
// ============================================================
int main() {
    // TODO 17-21: demo code
    Point p(1, 2);
    p.display();
    std::cout << std::endl;

    Rectangle r1(0, 10, 5, 0);
    Rectangle r2(0, 10, 5, 0);

    r1.display();
    r2.display();

    if (isSameSize(r1, r2))
        std::cout << "Same size" << std::endl;
    else
        std::cout << "Different size" << std::endl;

    ConstDemo d(10);
    std::cout << d.getValue() << std::endl;

    std::cout << d.constGetDouble() << std::endl;

    d.doubleValue();
    std::cout << d.getValue() << std::endl;

    return 0;
}
