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

Octagon::Octagon(const Octagon& other) noexcept {
    coordinates[0] = other.coordinates[0];
    coordinates[1] = other.coordinates[1];
    coordinates[2] = other.coordinates[2];
    coordinates[3] = other.coordinates[3];
    coordinates[4] = other.coordinates[4];
    coordinates[5] = other.coordinates[5];
    coordinates[6] = other.coordinates[6];
    coordinates[7] = other.coordinates[7];
}

Octagon::Octagon(const Vector<Point>& points) {
    if (points.get_size() < 8) {
        throw std::invalid_argument("Invalid number of vertices.");
    }
    bool isOctagon = checkOctagon(points[0], points[1], points[2], points[3], points[4], points[5], points[6], points[7]);

    if (!isOctagon) {
        throw std::invalid_argument("Invalid points.");
    }

    coordinates = {points[0], points[1], points[2], points[3], points[4], points[5], points[6], points[7]};

}

Octagon::Octagon(Octagon&& other) noexcept {
    this->coordinates[0] = std::move(other.coordinates[0]);
    this->coordinates[1] = std::move(other.coordinates[1]);
    this->coordinates[2] = std::move(other.coordinates[2]);
    this->coordinates[3] = std::move(other.coordinates[3]);
    this->coordinates[4] = std::move(other.coordinates[4]);
    this->coordinates[5] = std::move(other.coordinates[5]);
    this->coordinates[6] = std::move(other.coordinates[6]);
    this->coordinates[7] = std::move(other.coordinates[7]);
}

Octagon& Octagon::operator = (const Octagon& other) noexcept {
    if (this == &other) return *this;

    this->coordinates[0] = other.coordinates[0];
    this->coordinates[1] = other.coordinates[1];
    this->coordinates[2] = other.coordinates[2];
    this->coordinates[3] = other.coordinates[3];
    this->coordinates[4] = other.coordinates[4];
    this->coordinates[5] = other.coordinates[5];
    this->coordinates[6] = other.coordinates[6];
    this->coordinates[7] = other.coordinates[7];

    return *this;

}

Octagon& Octagon::operator = (Octagon&& move) noexcept {
    this->coordinates[0] = std::move(move.coordinates[0]);
    this->coordinates[1] = std::move(move.coordinates[1]);
    this->coordinates[2] = std::move(move.coordinates[2]);
    this->coordinates[3] = std::move(move.coordinates[3]);
    this->coordinates[4] = std::move(move.coordinates[4]);
    this->coordinates[5] = std::move(move.coordinates[5]);
    this->coordinates[6] = std::move(move.coordinates[6]);
    this->coordinates[7] = std::move(move.coordinates[7]);

    move.coordinates[0] = Point();
    move.coordinates[1] = Point();
    move.coordinates[2] = Point();
    move.coordinates[3] = Point();
    move.coordinates[4] = Point();
    move.coordinates[5] = Point();
    move.coordinates[6] = Point();
    move.coordinates[7] = Point();

    return *this;
}

bool Octagon::operator == (const Octagon& other) const{
    return  ( this->coordinates[0] == other.coordinates[0] &&
               this->coordinates[0] == other.coordinates[0] &&
               this->coordinates[1] == other.coordinates[1] &&
               this->coordinates[2] == other.coordinates[2] &&
               this->coordinates[3] == other.coordinates[3] &&
               this->coordinates[4] == other.coordinates[4] &&
               this->coordinates[5] == other.coordinates[5] &&
               this->coordinates[6] == other.coordinates[6] &&
               this->coordinates[7] == other.coordinates[7] ) ;
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
    is >> o.coordinates[0] >> o.coordinates[1]  >> o.coordinates[2] >> o.coordinates[3] >> o.coordinates[4] >> o.coordinates[5] >> o.coordinates[6]  >> o.coordinates[7];
    return is; 
}

std::ostream& operator<<(std::ostream& os, const Octagon& o) {
    os << o.coordinates[0] << std::endl;
    os << o.coordinates[1] << std::endl;
    os << o.coordinates[2] << std::endl;
    os << o.coordinates[3] << std::endl;
    os << o.coordinates[4] << std::endl; 
    os << o.coordinates[5] << std::endl; 
    os << o.coordinates[6] << std::endl; 
    os << o.coordinates[7] << std::endl; 

    return os;
}