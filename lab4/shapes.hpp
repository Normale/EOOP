#ifndef SHAPES_HPP
#define SHAPES_HPP


class Circle {

public:
    explicit Circle(double radius);

    double getRadius() const { return radius_; };
    void setRadius(double radius);

    virtual double getArea() const;

private:
    double radius_;
};


class Cylinder : public Circle {

public:
    Cylinder(double radius, double height);

    double getHeight() const { return height_; };
    void setHeight(double height);

    double getArea() const override;
    double getVolume() const;

private:
    double height_;
};

#endif //SHAPES_HPP