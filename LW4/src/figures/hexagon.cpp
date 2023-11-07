#include "../../include/figures/hexagon.hpp"

template <typename T>
bool Hexagon<T>::checkHexagon(
    const Point<T>& p1,
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5,
    const Point<T>& p6
) noexcept {
    double sum_x = p1.getX() + p2.getX() + p3.getX() + p4.getX() + p5.getX() + p6.getX();
    double sum_y = p1.getY() + p2.getY() + p3.getY() + p4.getY() + p5.getY() + p6.getY();

    Point<T> center(sum_x / 6.0, sum_y / 6.0);

    double inaccuracy = 1e-10;

    double lenToP1 = Point<T>::distance(center, p1);
    double lenToP2 = Point<T>::distance(center, p2);
    double lenToP3 = Point<T>::distance(center, p3);
    double lenToP4 = Point<T>::distance(center, p4);
    double lenToP5 = Point<T>::distance(center, p5);
    double lenToP6 = Point<T>::distance(center, p6);


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

template <typename T>
Hexagon<T>::Hexagon(const Vector<Point<T>>& points) {
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

    this->coordinates = {points[0], points[1], points[2], points[3], points[4], points[5]};

}

template <typename T>
Hexagon<T>::Hexagon(const Hexagon<T>& other) noexcept {
    this->coordinates[0] = other.coordinates[0];
    this->coordinates[1] = other.coordinates[1];
    this->coordinates[2] = other.coordinates[2];
    this->coordinates[3] = other.coordinates[3];
    this->coordinates[4] = other.coordinates[4];
    this->coordinates[5] = other.coordinates[5];
}

template <typename T>
Hexagon<T>::Hexagon(Hexagon<T>&& other) noexcept {
    this->coordinates[0] = std::move(other.coordinates[0]);
    this->coordinates[1] = std::move(other.coordinates[1]);
    this->coordinates[2] = std::move(other.coordinates[2]);
    this->coordinates[3] = std::move(other.coordinates[3]);
    this->coordinates[4] = std::move(other.coordinates[4]);
    this->coordinates[5] = std::move(other.coordinates[5]);
}

template <typename T>
Hexagon<T>& Hexagon<T>::operator = (const Hexagon<T>& other) noexcept {
    if (this == &other) return *this;

    this->coordinates[0] = other.coordinates[0];
    this->coordinates[1] = other.coordinates[1];
    this->coordinates[2] = other.coordinates[2];
    this->coordinates[3] = other.coordinates[3];
    this->coordinates[4] = other.coordinates[4];
    this->coordinates[5] = other.coordinates[5];
    return *this;

}

template <typename T>
Hexagon<T>& Hexagon<T>::operator = (Hexagon<T>&& move) noexcept {
    this->coordinates[0] = std::move(move.coordinates[0]);
    this->coordinates[1] = std::move(move.coordinates[1]);
    this->coordinates[2] = std::move(move.coordinates[2]);
    this->coordinates[3] = std::move(move.coordinates[3]);
    this->coordinates[4] = std::move(move.coordinates[4]);
    this->coordinates[5] = std::move(move.coordinates[5]);

    move.coordinates[0] = Point<T>();
    move.coordinates[1] = Point<T>();
    move.coordinates[2] = Point<T>();
    move.coordinates[3] = Point<T>();
    move.coordinates[4] = Point<T>();
    move.coordinates[5] = Point<T>();

    return *this;
}

template <typename T>
bool Hexagon<T>::operator == (const Hexagon<T>& other) const{
    return  ( this->coordinates[0] == other.coordinates[0] &&
               this->coordinates[0] == other.coordinates[0] &&
               this->coordinates[1] == other.coordinates[1] &&
               this->coordinates[2] == other.coordinates[2] &&
               this->coordinates[3] == other.coordinates[3] &&
               this->coordinates[4] == other.coordinates[4] &&
               this->coordinates[5] == other.coordinates[5]);
}

template <typename T>
Hexagon<T>::Hexagon(
    const Point<T>& p1, 
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5,
    const Point<T>& p6
    ) {

    bool isHexagon = checkHexagon(p1, p2, p3, p4, p5, p6);

    if (!isHexagon) {
        throw std::invalid_argument("Invalid points.");
    }

    this->coordinates = {p1, p2, p3, p4, p5, p6};
}

template <typename T>
Point<T> Hexagon<T>::geometricCenter() const noexcept{
    double center_x = 0.0;
    double center_y = 0.0;

    for (size_t i = 0; i < this->coordinates.get_size(); ++i) {
        center_x += this->coordinates[i].getX();
        center_y += this->coordinates[i].getY();
    }

    return Point<T>(center_x / 6.0, center_y / 6.0);
}

template <typename T>
double Hexagon<T>::area() const noexcept {
    double sideLen = Point<T>::distance(this->coordinates[0], this->coordinates[1]);

    return (3 * sqrt(3) / 2) * pow(sideLen, 2);
}

template <typename T>
bool Hexagon<T>::operator != (const Hexagon<T>& other) const {
    return !(*this == other);
}

template <typename T>
Hexagon<T>::operator double() const {
    double sideLen = Point<T>::distance(this->coordinates[0], this->coordinates[1]);

    return (3 * sqrt(3) / 2) * pow(sideLen, 2);
}

template <typename U>
std::istream& operator>>(std::istream& is, Hexagon<U>& p) {
    is >> p.coordinates[0] >> p.coordinates[1] >> p.coordinates[2] >> p.coordinates[3] >> p.coordinates[4] >> p.coordinates[5];
    return is; 
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const Hexagon<U>& o) {
    os << o.coordinates[0] << std::endl;
    os << o.coordinates[1] << std::endl;
    os << o.coordinates[2] << std::endl;
    os << o.coordinates[3] << std::endl;
    os << o.coordinates[4] << std::endl; 
    os << o.coordinates[5] << std::endl; 

    return os;
}