#include "../../include/figures/point.hpp"
#include "math.h"

template <typename T>
Point<T>::Point(const T& x, const T& y) noexcept: x(x), y(y) {}


template <typename T>
Point<T>::Point(const std::initializer_list<T>& list) {
    if (list.size() != 2) {
        throw std::invalid_argument("List must contains two coordinates (x, y)");
    }

    x = *(list.begin());
    y = *(list.end() - 1);
}

template <typename T>
const T& Point<T>::getX() const noexcept {
    return this->x;
}

template <typename T>
const T& Point<T>::getY() const noexcept {
    return this->y;
}

template <typename T>
void Point<T>::setX(T val) noexcept {
    this->x = val;
}

template <typename T>
void Point<T>::setY(T val) noexcept {
    this->y = val;
}


template <typename T>
double Point<T>::distance(const Point<T>& p1, const Point<T>& p2) {
    double dx = p2.getX() - p1.getX();
    double dy = p2.getY() - p1.getY();

    double len = std::sqrt(dx * dx + dy * dy);

    return len;
}


template <typename U>
std::istream& operator >> (std::istream& is, Point<U>& p) {
    is >> p.x >> p.y;
    return is;
}

template <typename U>
std::ostream& operator <<(std::ostream& os, const Point<U>& p) {
    os << p.x << ", " << p.y;
    return os;
}
