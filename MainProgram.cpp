#include <iostream>
#include <string>
#include <cmath>

class Rectangle; // forward declaration

class Point {
private:
    double x;
    double y;

public:
    Point(double x, double y) : x(x), y(y) {}

    double getX() const { return x; }

    double getY() const { return y; }

    void display() const {
        std::cout << "(" << x << ", " << y << ")";
    }

    friend class Rectangle;
};

class Rectangle {
private:
    Point topLeft;
    Point bottomRight;

public:
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {}

    double getWidth() const {
        return std::abs(bottomRight.x - topLeft.x);
    }

    double getHeight() const {
        return std::abs(topLeft.y - bottomRight.y);
    }

    double getArea() const {
        return getWidth() * getHeight();
    }

    void display() const {
        std::cout << "Top Left: ";
        topLeft.display();

        std::cout << ", Bottom Right: ";
        bottomRight.display();

        std::cout << ", Width: " << getWidth()
                  << ", Height: " << getHeight()
                  << ", Area: " << getArea() << std::endl;
    }

    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};

bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return r1.getWidth() == r2.getWidth() &&
           r1.getHeight() == r2.getHeight();
}

class ConstDemo {
private:
    int value;

public:
    ConstDemo(int v) : value(v) {}

    int getValue() const {
        return value;
    }

    void doubleValue() {
        value *= 2;
    }

    int constGetDouble() const {
        return value * 2;
    }
};

int main() {
    Point p1(2, 5);
    p1.display();
    std::cout << std::endl;

    Rectangle r1(0, 10, 5, 0);
    Rectangle r2(2, 8, 7, -2);

    r1.display();
    r2.display();

    if (isSameSize(r1, r2))
        std::cout << "Same size" << std::endl;
    else
        std::cout << "Different size" << std::endl;

    ConstDemo d(10);

    std::cout << "Value: " << d.getValue() << std::endl;
    std::cout << "Double without change: " << d.constGetDouble() << std::endl;

    d.doubleValue();

    std::cout << "After doubleValue: " << d.getValue() << std::endl;

    return 0;
}
