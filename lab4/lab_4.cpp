/**
   Unit tests for EOOP task4 (Circle and Cylinder classes).
   Please do not modify this file.

   Note that this is in a big part "code reading" exercise.
   Based on this file you should implement two classes mentioned above,
   with proper interface in the .hpp file, and proper implementation in the
   right .cpp file.

   Make sure that you use inheritance and reuse your code.

   Please make sure that you compile your solution with warnings enabled and that there are no warnings during compilation. You can do this via the following command:
   g++ -Wall -Wextra -Werror -pedantic *.cpp *.hpp

 */

#include "shapes.hpp"
#include <iostream>
#include <cmath>
#include <cfloat>
#include <algorithm>

void error_message(const std::string& message, double value, double expected) {
    std::cerr << "Error - " << message << ", got: " << value << " expected " << expected << std::endl;
}

void error_message(const std::string& message) {
    std::cerr << "Error - " << message << "!" << std::endl;
}

/**
   Check if two doubles are equal or nearly equal.

   You can think about this function as `==` operator that is impervious to the
   problems in floating point numbers precision.

   If you want to know more then you can read the following blog entry:
   https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
 */
bool nearlyEqual(double a, double b, double epsilon = 1e-5) {
    return (fabs(a - b) <= epsilon * std::max(fabs(a), fabs(b)));
}

void check_circle_radius() {
    Circle circle(7);

    double radius = circle.getRadius();
    double expected_radius = 7;
    if (radius != expected_radius) {
        error_message("wrong radius in Circle::getRadius", radius, expected_radius);
    }

    try {
        circle.setRadius(0);
        error_message("missing exception in Circle::setRadius");
    } catch(std::invalid_argument& e) { }

    try {
        Circle dummy(-1);
        error_message("missing exception for a wrong value of radius in Circle c-tor");
    } catch(std::invalid_argument& e) { }
}

void check_cylinder_radius() {
    Cylinder cylinder(7, 42);

    double radius = cylinder.getRadius();
    double expected_radius = 7;
    if (radius != expected_radius) {
        error_message("wrong radius in Cylinder::getRadius", radius, expected_radius);
    }

    try {
        cylinder.setRadius(0);
        error_message("missing exception in Cylinder::setRadius");
    } catch(std::invalid_argument& e) { }

    try {
        Cylinder dummy(-1, 42);
        error_message("missing exception for a wrong value of radius in Cylinder c-tor");
    } catch(std::invalid_argument& e) { }
}

void check_cylinder_height() {
    Cylinder cylinder(7, 42);

    double height = cylinder.getHeight();
    double expected_height = 42;
    if (height != expected_height) {
        error_message("wrong height in Cylinder::getHeight", height, expected_height);
    }

    try {
        cylinder.setHeight(0);
        error_message("missing exception in Cylinder::setHeight");
    } catch(std::invalid_argument& e) { }

    try {
        Cylinder dummy(7, -1);
        error_message("missing exception for a wrong value of height in Cylinder c-tor");
    } catch(std::invalid_argument& e) { }
}

void check_circle_area() {
    Circle circle(7);
    double area = circle.getArea();
    double expected_area = 153.938;
    if (!nearlyEqual(area, expected_area)) {
        error_message("wrong circle area", area, expected_area);
    }
}

// Technically speaking it's called surface, but for the sake of the excercise let's
// assume it's called an area
void check_cylinder_area() {
    Cylinder cylinder(7, 42);
    double area = cylinder.getArea();
    double expected_area = 2155.13;
    if (!nearlyEqual(area, expected_area)) {
        error_message("wrong cylinder area", area, expected_area);
    }
}

void check_cylinder_volume() {
    Cylinder cylinder(7, 42);
    double volume = cylinder.getVolume();
    double expected_volume = 6465.3976;
    if (!nearlyEqual(volume, expected_volume)) {
        error_message("wrong cylinder volume", volume, expected_volume);
    }
}

int main() {
    check_circle_radius();
    check_circle_area();
    check_cylinder_radius();
    check_cylinder_height();
    check_cylinder_area();
    check_cylinder_volume();
    std::cout << "End of tests." << std::endl;
    return 0;
}
