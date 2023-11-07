#pragma once

#include <iostream>


#include "../../containers/vector.hpp"

template <typename T>
class Point final{
private:
    T x;
    T y;

public:

    Point() = default;
    Point(const std::initializer_list<T>&);
    Point(const T&, const T&) noexcept;

    const T& getX() const noexcept;
    const T& getY() const noexcept;

    void setX(T x) noexcept;
    void setY(T y) noexcept;

    static double distance(const Point<T>& p1, const Point<T>& p2);


    template <typename U>
    friend std::istream& operator >> (std::istream& is, Point<U>& p);

    template <typename U>
    friend std::ostream& operator << (std::ostream& os, const Point<U>& p);

    virtual ~Point() = default;

};
