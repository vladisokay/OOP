#include "../../include/figures/hexagon.hpp"

double Hexagon::angle(
    const Point& p1,
    const Point& p2,
    const Point& p3
) noexcept {
    double a = Point::distance(p1, p2);
    double b = Point::distance(p2, p3);
    double c = Point::distance(p3, p1);

    return std::acos((a * a + b * b - c * c) / (2 * a * b));
}

bool Hexagon::checkHexagon(
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5,
    const Point& p6
) noexcept {

    double inaccuracy = 1e-10;
    double sideLength = Point::distance(p1, p2);
    for (const Point& p : {p2, p3, p4, p5, p6}) {
        if (std::abs(Point::distance(p1, p) - sideLength) > inaccuracy) {
            std::cout << p.getX() << ' ' << p.getY() << std::endl;
            return false; 
        }
    }

    // Вычисляем углы между смежными сторонами
    double angleValue = angle(p1, p2, p3);
    for (const Point& p : {p3, p4, p5, p6}) {
        if (std::abs(angle(p, p1, p2) - angleValue) > inaccuracy) {
            return false; 
        }
    }

    return true; 

}

Hexagon::Hexagon(const Hexagon& other) noexcept :
    _topOne(other._topOne),
    _topTwo(other._topTwo),
    _topThree(other._topThree),
    _topFour(other._topFour),
    _topFive(other._topFive),
    _topSix(other._topSix) {}

Hexagon::Hexagon(Hexagon&& other) noexcept {
    this->_topOne = std::move(other._topOne);
    this->_topTwo = std::move(other._topTwo);
    this->_topThree = std::move(other._topThree);
    this->_topFour = std::move(other._topFour);
    this->_topFive = std::move(other._topFive);
    this->_topSix = std::move(other._topSix);
}

Hexagon& Hexagon::operator = (const Hexagon& other) noexcept {
    if (this == &other) return *this;

    this->_topOne = other._topOne;
    this->_topTwo = other._topTwo;
    this->_topThree = other._topThree;
    this->_topFour = other._topFour;
    this->_topFive = other._topFive;
    this->_topSix = other._topSix;
    return *this;

}

Hexagon& Hexagon::operator = (Hexagon&& move) noexcept {
    this->_topOne = std::move(move._topOne);
    this->_topTwo = std::move(move._topTwo);
    this->_topThree = std::move(move._topThree);
    this->_topFour = std::move(move._topFour);
    this->_topFive = std::move(move._topFive);
    this->_topSix = std::move(move._topSix);

    return *this;
}

bool Hexagon::operator == (const Hexagon& other) const{
    return  ( this->_topOne == other._topOne &&
               this->_topOne == other._topOne &&
               this->_topTwo == other._topTwo &&
               this->_topThree == other._topThree &&
               this->_topFour == other._topFour &&
               this->_topFive == other._topFive &&
               this->_topSix == other._topSix);
}

Hexagon::Hexagon(
    const Point& p1, 
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5,
    const Point& p6
    ) {

    bool isHexagon = checkHexagon(p1, p2, p3, p4, p5, p6);

    if (!isHexagon) {
        throw std::invalid_argument("Invalid points.");
    }

    coordinates = {p1, p2, p3, p4, p5, p6};
}

Point Hexagon::geometricCenter() const noexcept{
    double center_x = 0.0;
    double center_y = 0.0;

    for (size_t i = 0; i < coordinates.get_size(); ++i) {
        center_x += coordinates[i].getX();
        center_y += coordinates[i].getY();
    }

    return Point(center_x / 6.0, center_y / 6.0);
}

double Hexagon::area() const noexcept {
    double sideLen = Point::distance(coordinates[0], coordinates[1]);

    return (3 * sqrt(3) / 2) * pow(sideLen, 2);
}

bool Hexagon::operator != (const Hexagon& other) const {
    return !(*this == other);
}

Hexagon::operator double() const {
    double sideLen = Point::distance(coordinates[0], coordinates[1]);

    return (3 * sqrt(3) / 2) * pow(sideLen, 2);
}

std::istream& operator>>(std::istream& is, Hexagon& p) {
    is >> p._topOne >> p._topTwo >> p._topThree >> p._topFour >> p._topFive >> p._topSix;
    return is; 
}

std::ostream& operator<<(std::ostream& os, const Hexagon& o) {
    os << o._topOne << std::endl;
    os << o._topTwo << std::endl;
    os << o._topThree << std::endl;
    os << o._topFour << std::endl;
    os << o._topFive << std::endl; 
    os << o._topSix << std::endl; 

    return os;
}