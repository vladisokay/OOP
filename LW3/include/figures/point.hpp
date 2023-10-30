#pragma once

#include <iostream>

#include "../../containers/vector.hpp"


class Point final{
public:

    Point() = default;
    Point(const std::initializer_list<double>&);
    Point(double, double ) noexcept;
    Point(const Point& other);
    Point(Point&& move) noexcept;

    const double getX() const noexcept;
    const double getY() const noexcept;

    void setX(double) noexcept;
    void setY(double) noexcept;

    static double distance(const Point& p1, const Point& p2);


    Point& operator=(const Point& other);
    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    bool operator == (const Point& other) const noexcept;
    bool operator != (const Point& other) const noexcept;

    friend std::istream& operator >> (std::istream& is, Point& p);
    friend std::ostream& operator << (std::ostream& os, const Point& p);

    virtual ~Point() = default;

private:
    double x;
    double y;
    

};
