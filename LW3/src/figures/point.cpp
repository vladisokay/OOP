#include "../../include/figures/point.hpp"
#include "math.h"


Point::Point(double x, double y) noexcept: x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::Point(Point&& move) noexcept {
    this->x = std::move(move.x);
    this->y = std::move(move.y);
}

Point::Point(const std::initializer_list<double>& list) {
    if (list.size() != 2) {
        throw std::invalid_argument("List must contains two coordinates (x, y)");
    }

    x = *(list.begin());
    y = *(list.end() - 1);
}

const double Point::getX() const noexcept {
    return this->x;
}

const double Point::getY() const noexcept {
    return this->y;
}

void Point::setX(double val) noexcept {
    this->x = val;
}

void Point::setY(double val) noexcept {
    this->y = val;
}




double Point::distance(const Point& p1, const Point& p2) {
    double dx = p2.getX() - p1.getX();
    double dy = p2.getY() - p1.getY();

    double len = std::sqrt(dx * dx + dy * dy);

    return len;
}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Point Point::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}

Point Point::operator-(const Point& other) const {
    return Point(x - other.x, y - other.y);
}

bool Point::operator == (const Point& other) const noexcept {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const noexcept {
    return !(*this == other);
}

std::istream& operator >> (std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

std::ostream& operator <<(std::ostream& os, const Point& p) {
    os << p.x << ", " << p.y;
    return os;
}
