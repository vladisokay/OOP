#include "../../include/figures/pentagon.hpp"

double Pentagon::angle(
    const Point& p1,
    const Point& p2,
    const Point& p3
) noexcept {
    double a = Point::distance(p1, p2);
    double b = Point::distance(p2, p3);
    double c = Point::distance(p3, p1);

    return std::acos((a * a + b * b - c * c) / (2 * a * b));
}

bool Pentagon::checkPentagon(
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5
    
) noexcept {
    bool isPentagon = false;

    double inaccuracy = 1e-10;
    double sideLen = Point::distance(p1, p2);

    double lenToP1P2 = Point::distance(p1, p2);
    double lenToP2P3 = Point::distance(p2, p3);
    double lenToP3P4 = Point::distance(p3, p4);
    double lenToP4P5 = Point::distance(p4, p5);
    double lenToP5P1 = Point::distance(p5, p1);

    if (
        std::abs(lenToP1P2 - sideLen) < inaccuracy &&
        std::abs(lenToP2P3 - sideLen) < inaccuracy &&
        std::abs(lenToP3P4 - sideLen) < inaccuracy &&
        std::abs(lenToP4P5 - sideLen) < inaccuracy &&
        std::abs(lenToP5P1 - sideLen) < inaccuracy 
    ) {
        isPentagon = true;
    }

    //std::abs(angle(vertices[i], vertices[(i + 1) % 5], vertices[(i + 2) % 5]) - angleValue) > 1e-6) 

    double angleValue = Pentagon::angle(p1, p2, p3);
    if (std::abs(Pentagon::angle(p1, p2, p3) - angleValue) < inaccuracy &&
        std::abs(Pentagon::angle(p2, p3, p4) - angleValue) < inaccuracy &&
        std::abs(Pentagon::angle(p3, p4, p5) - angleValue) < inaccuracy ){
            isPentagon = true;
        }

    return isPentagon;

}

Pentagon::Pentagon(const Pentagon& other) noexcept :
    _topOne(other._topOne),
    _topTwo(other._topTwo),
    _topThree(other._topThree),
    _topFour(other._topFour),
    _topFive(other._topFive) {}

Pentagon::Pentagon(Pentagon&& other) noexcept {
    this->_topOne = std::move(other._topOne);
    this->_topTwo = std::move(other._topTwo);
    this->_topThree = std::move(other._topThree);
    this->_topFour = std::move(other._topFour);
    this->_topFive = std::move(other._topFive);
}

Pentagon& Pentagon::operator = (const Pentagon& other) noexcept {
    if (this == &other) return *this;

    this->_topOne = other._topOne;
    this->_topTwo = other._topTwo;
    this->_topThree = other._topThree;
    this->_topFour = other._topFour;
    this->_topFive = other._topFive;

    return *this;

}

Pentagon& Pentagon::operator = (Pentagon&& move) noexcept {
    this->_topOne = std::move(move._topOne);
    this->_topTwo = std::move(move._topTwo);
    this->_topThree = std::move(move._topThree);
    this->_topFour = std::move(move._topFour);
    this->_topFive = std::move(move._topFive);

    return *this;
}

bool Pentagon::operator == (const Pentagon& other) const{
    return  ( this->_topOne == other._topOne &&
               this->_topOne == other._topOne &&
               this->_topTwo == other._topTwo &&
               this->_topThree == other._topThree &&
               this->_topFour == other._topFour &&
               this->_topFive == other._topFive ) ;
}

Pentagon::Pentagon(
    const Point& p1, 
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5
    ) {

    bool isPentagon = checkPentagon(p1, p2, p3, p4, p5);

    if (!isPentagon) {
        throw std::invalid_argument("Invalid points.");
    }

    coordinates = {p1, p2, p3, p4, p5};
}

Point Pentagon::geometricCenter() const noexcept{
    double center_x = 0.0;
    double center_y = 0.0;

    for (size_t i = 0; i < coordinates.get_size(); ++i) {
        center_x += coordinates[i].getX();
        center_y += coordinates[i].getY();
    }

    return Point(center_x / 5.0, center_y / 5.0);
}

double Pentagon::area() const noexcept {
    double sideLen = Point::distance(coordinates[0], coordinates[1]);

    return 0.25 * (5 * sqrt(5) * pow(sideLen, 2));
}

bool Pentagon::operator != (const Pentagon& other) const {
    return !(*this == other);
}

Pentagon::operator double() const {
    double sideLen = Point::distance(coordinates[0], coordinates[1]);

    return 0.25 * (5 * sqrt(5) * pow(sideLen, 2));
}

std::istream& operator>>(std::istream& is, Pentagon& p) {
    is >> p._topOne >> p._topTwo >> p._topThree >> p._topFour >> p._topFive;
    return is; 
}

std::ostream& operator<<(std::ostream& os, const Pentagon& p) {
    os << p._topOne << std::endl;
    os << p._topTwo << std::endl;
    os << p._topThree << std::endl;
    os << p._topFour << std::endl;
    os << p._topFive << std::endl; 

    return os;
}