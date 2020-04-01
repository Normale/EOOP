#include "shapes.hpp"
#include "cmath"
#include "stdexcept"


Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::setRadius(double radius) {
    if (radius <= 0) throw std::invalid_argument("Radius must be positive");
    radius_ = radius;
}

double Circle::getArea() const {
    return M_PI * pow(getRadius(), 2);
}

Cylinder::Cylinder(double radius, double height) : Circle(radius) {
    setHeight(height);
}

void Cylinder::setHeight(double height) {
    if (height <= 0) throw std::invalid_argument("Height must be positive");
    height_ = height;
}

double Cylinder::getArea() const {
    return 2 * (Circle::getArea() + M_PI * getRadius() * getHeight());
}

double Cylinder::getVolume() const {
    return Circle::getArea() * getHeight();
}