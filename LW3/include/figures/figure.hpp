#pragma once

#include <iostream>
#include <cmath>

#include "../../containers/vector.hpp"
#include "../../containers/vector.cpp"
#include "point.hpp"

class Figure {
protected:
    Figure() = default;
    Vector<Point> coordinates;

public:
    virtual ~Figure() = default;

    virtual Point geometricCenter() const = 0;
    virtual double area() const = 0;

    virtual operator double() const = 0;
};