#include "../../include/figures/octagon.hpp"

bool Octagon::checkOctagon(
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5,
    const Point& p6,
    const Point& p7,
    const Point& p8
) noexcept {
    double sum_x = p1.getX() + p2.getX() + p3.getX() + p4.getX() + p5.getX() + p6.getX() + p7.getX() + p8.getX();
    double sum_y = p1.getY() + p2.getY() + p3.getY() + p4.getY() + p5.getY() + p6.getY() + p7.getY() + p8.getY();

    Point center(sum_x / 8.0, sum_y / 8.0);

    double inaccuracy = 1e-10;

    double lenToP1 = Point::distance(center, p1);
    double lenToP2 = Point::distance(center, p2);
    double lenToP3 = Point::distance(center, p3);
    double lenToP4 = Point::distance(center, p4);
    double lenToP5 = Point::distance(center, p5);
    double lenToP6 = Point::distance(center, p6);
    double lenToP7 = Point::distance(center, p7);
    double lenToP8 = Point::distance(center, p8);

    if (
        std::abs(lenToP1 - lenToP2) < inaccuracy &&
        std::abs(lenToP2 - lenToP3) < inaccuracy &&
        std::abs(lenToP3 - lenToP4) < inaccuracy &&
        std::abs(lenToP4 - lenToP5) < inaccuracy &&
        std::abs(lenToP5 - lenToP6) < inaccuracy &&
        std::abs(lenToP6 - lenToP7) < inaccuracy &&
        std::abs(lenToP7 - lenToP8) < inaccuracy
    ) {
        return true;
    }

    return false;

}

Octagon::Octagon(const Octagon& other) noexcept :
    _topOne(other._topOne),
    _topTwo(other._topTwo),
    _topThree(other._topThree),
    _topFour(other._topFour),
    _topFive(other._topFive),
    _topSix(other._topSix),
    _topSeven(other._topSeven),
    _topEight(other._topEight) {}

Octagon::Octagon(Octagon&& other) noexcept {
    this->_topOne = std::move(other._topOne);
    this->_topTwo = std::move(other._topTwo);
    this->_topThree = std::move(other._topThree);
    this->_topFour = std::move(other._topFour);
    this->_topFive = std::move(other._topFive);
    this->_topSix = std::move(other._topSix);
    this->_topSeven = std::move(other._topSeven);
    this->_topEight = std::move(other._topEight);
}

Octagon& Octagon::operator = (const Octagon& other) noexcept {
    if (this == &other) return *this;

    this->_topOne = other._topOne;
    this->_topTwo = other._topTwo;
    this->_topThree = other._topThree;
    this->_topFour = other._topFour;
    this->_topFive = other._topFive;
    this->_topSix = other._topSix;
    this->_topSeven = other._topSeven;
    this->_topEight = other._topEight;

    return *this;

}

Octagon& Octagon::operator = (Octagon&& move) noexcept {
    this->_topOne = std::move(move._topOne);
    this->_topTwo = std::move(move._topTwo);
    this->_topThree = std::move(move._topThree);
    this->_topFour = std::move(move._topFour);
    this->_topFive = std::move(move._topFive);
    this->_topSix = std::move(move._topSix);
    this->_topSeven = std::move(move._topSeven);
    this->_topEight = std::move(move._topEight);

    return *this;
}

bool Octagon::operator == (const Octagon& other) const{
    return  ( this->_topOne == other._topOne &&
               this->_topOne == other._topOne &&
               this->_topTwo == other._topTwo &&
               this->_topThree == other._topThree &&
               this->_topFour == other._topFour &&
               this->_topFive == other._topFive &&
               this->_topSix == other._topSix &&
               this->_topSeven == other._topSeven &&
               this->_topEight == other._topEight ) ;
}

Octagon::Octagon(
    const Point& p1, 
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5,
    const Point& p6,
    const Point& p7,
    const Point& p8
    ) {

    bool isOctagon = checkOctagon(p1, p2, p3, p4, p5, p6, p7, p8);

    if (!isOctagon) {
        throw std::invalid_argument("Invalid points.");
    }

    coordinates = {p1, p2, p3, p4, p5, p6, p7, p8};
}

Point Octagon::geometricCenter() const noexcept{
    double center_x = 0.0;
    double center_y = 0.0;

    for (size_t i = 0; i < coordinates.get_size(); ++i) {
        center_x += coordinates[i].getX();
        center_y += coordinates[i].getY();
    }
    std::cout << "lyalyalya" << std::endl;
    return Point(center_x / 8.0, center_y / 8.0);
}

double Octagon::area() const noexcept {
    double sideLen = Point::distance(coordinates[0], coordinates[1]);

    return 2 * std::pow(sideLen, 2) * (1 + std::sqrt(2));
}

bool Octagon::operator != (const Octagon& other) const {
    return !(*this == other);
}

Octagon::operator double() const {
    double sideLen = Point::distance(coordinates[0], coordinates[1]);

    return 2 * std::pow(sideLen, 2) * (1 + std::sqrt(2));
}

std::istream& operator>>(std::istream& is, Octagon& o) {
    is >> o._topOne >> o._topTwo >> o._topThree >> o._topFour >> o._topFive >> o._topSix >> o._topSeven >> o._topEight;
    return is; 
}

std::ostream& operator<<(std::ostream& os, const Octagon& o) {
    os << o._topOne << std::endl;
    os << o._topTwo << std::endl;
    os << o._topThree << std::endl;
    os << o._topFour << std::endl;
    os << o._topFive << std::endl; 
    os << o._topSix << std::endl; 
    os << o._topSeven << std::endl; 
    os << o._topEight << std::endl; 

    return os;
}