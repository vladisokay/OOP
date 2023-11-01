#include "../../include/figures/hexagon.hpp"


bool Hexagon::checkHexagon(
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5,
    const Point& p6
) noexcept {
    double sum_x = p1.getX() + p2.getX() + p3.getX() + p4.getX() + p5.getX() + p6.getX();
    double sum_y = p1.getY() + p2.getY() + p3.getY() + p4.getY() + p5.getY() + p6.getY();

    Point center(sum_x / 6.0, sum_y / 6.0);

    double inaccuracy = 1e-10;

    double lenToP1 = Point::distance(center, p1);
    double lenToP2 = Point::distance(center, p2);
    double lenToP3 = Point::distance(center, p3);
    double lenToP4 = Point::distance(center, p4);
    double lenToP5 = Point::distance(center, p5);
    double lenToP6 = Point::distance(center, p6);


    if (
        std::abs(lenToP1 - lenToP2) < inaccuracy &&
        std::abs(lenToP2 - lenToP3) < inaccuracy &&
        std::abs(lenToP3 - lenToP4) < inaccuracy &&
        std::abs(lenToP4 - lenToP5) < inaccuracy &&
        std::abs(lenToP5 - lenToP6) < inaccuracy
    ) {
        return true;
    }

    return false;
}

Hexagon::Hexagon(const Vector<Point>& points) {
    if (points.get_size() < 6) {
        throw std::invalid_argument("Invalid number of vertices.");
    }
    bool isHexagon = checkHexagon(points[0],
                                  points[1],
                                  points[2],
                                  points[3],
                                  points[4],
                                  points[5]);
    if (!isHexagon) {
        throw std::invalid_argument("Invalid points.");
    }

    coordinates = {points[0], points[1], points[2], points[3], points[4], points[5]};

}

Hexagon::Hexagon(const Hexagon& other) noexcept {
    coordinates[0] = other.coordinates[0];
    coordinates[1] = other.coordinates[1];
    coordinates[2] = other.coordinates[2];
    coordinates[3] = other.coordinates[3];
    coordinates[4] = other.coordinates[4];
    coordinates[5] = other.coordinates[5];
}

Hexagon::Hexagon(Hexagon&& other) noexcept {
    this->coordinates[0] = std::move(other.coordinates[0]);
    this->coordinates[1] = std::move(other.coordinates[1]);
    this->coordinates[2] = std::move(other.coordinates[2]);
    this->coordinates[3] = std::move(other.coordinates[3]);
    this->coordinates[4] = std::move(other.coordinates[4]);
    this->coordinates[5] = std::move(other.coordinates[5]);
}

Hexagon& Hexagon::operator = (const Hexagon& other) noexcept {
    if (this == &other) return *this;

    this->coordinates[0] = other.coordinates[0];
    this->coordinates[1] = other.coordinates[1];
    this->coordinates[2] = other.coordinates[2];
    this->coordinates[3] = other.coordinates[3];
    this->coordinates[4] = other.coordinates[4];
    this->coordinates[5] = other.coordinates[5];
    return *this;

}

Hexagon& Hexagon::operator = (Hexagon&& move) noexcept {
    this->coordinates[0] = std::move(move.coordinates[0]);
    this->coordinates[1] = std::move(move.coordinates[1]);
    this->coordinates[2] = std::move(move.coordinates[2]);
    this->coordinates[3] = std::move(move.coordinates[3]);
    this->coordinates[4] = std::move(move.coordinates[4]);
    this->coordinates[5] = std::move(move.coordinates[5]);

    move.coordinates[0] = Point();
    move.coordinates[1] = Point();
    move.coordinates[2] = Point();
    move.coordinates[3] = Point();
    move.coordinates[4] = Point();
    move.coordinates[5] = Point();

    return *this;
}

bool Hexagon::operator == (const Hexagon& other) const{
    return  ( this->coordinates[0] == other.coordinates[0] &&
               this->coordinates[0] == other.coordinates[0] &&
               this->coordinates[1] == other.coordinates[1] &&
               this->coordinates[2] == other.coordinates[2] &&
               this->coordinates[3] == other.coordinates[3] &&
               this->coordinates[4] == other.coordinates[4] &&
               this->coordinates[5] == other.coordinates[5]);
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
    is >> p.coordinates[0] >> p.coordinates[1] >> p.coordinates[2] >> p.coordinates[3] >> p.coordinates[4] >> p.coordinates[5];
    return is; 
}

std::ostream& operator<<(std::ostream& os, const Hexagon& o) {
    os << o.coordinates[0] << std::endl;
    os << o.coordinates[1] << std::endl;
    os << o.coordinates[2] << std::endl;
    os << o.coordinates[3] << std::endl;
    os << o.coordinates[4] << std::endl; 
    os << o.coordinates[5] << std::endl; 

    return os;
}