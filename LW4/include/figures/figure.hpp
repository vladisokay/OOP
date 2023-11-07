#pragma once

#include <iostream>
#include <cmath>

#include "../../containers/vector.hpp"
#include "../../containers/vector.cpp"
#include "point.hpp"

template <typename T>
class Figure {
protected:
    Figure() = default;
    Vector<Point<T>> coordinates;

public:
    virtual ~Figure() = default;

    virtual Point<T> geometricCenter() const = 0;
    virtual double area() const = 0;

    virtual operator double() const = 0;
};