#include "../../include/figures/octagon.hpp"

template <typename T>
bool Octagon<T>::checkOctagon(
    const Point<T>& p1,
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5,
    const Point<T>& p6,
    const Point<T>& p7,
    const Point<T>& p8
) noexcept {
    double sum_x = p1.getX() + p2.getX() + p3.getX() + p4.getX() + p5.getX() + p6.getX() + p7.getX() + p8.getX();
    double sum_y = p1.getY() + p2.getY() + p3.getY() + p4.getY() + p5.getY() + p6.getY() + p7.getY() + p8.getY();

    Point<T> center(sum_x / 8.0, sum_y / 8.0);

    double inaccuracy = 1e-10;

    double lenToP1 = Point<T>::distance(center, p1);
    double lenToP2 = Point<T>::distance(center, p2);
    double lenToP3 = Point<T>::distance(center, p3);
    double lenToP4 = Point<T>::distance(center, p4);
    double lenToP5 = Point<T>::distance(center, p5);
    double lenToP6 = Point<T>::distance(center, p6);
    double lenToP7 = Point<T>::distance(center, p7);
    double lenToP8 = Point<T>::distance(center, p8);

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

template <typename T>
Octagon<T>::Octagon(const Octagon<T>& other) noexcept {
    this->coordinates[0] = other.coordinates[0];
    this->coordinates[1] = other.coordinates[1];
    this->coordinates[2] = other.coordinates[2];
    this->coordinates[3] = other.coordinates[3];
    this->coordinates[4] = other.coordinates[4];
    this->coordinates[5] = other.coordinates[5];
    this->coordinates[6] = other.coordinates[6];
    this->coordinates[7] = other.coordinates[7];
}

template <typename T>
Octagon<T>::Octagon(const Vector<Point<T>>& points) {
    if (points.get_size() < 8) {
        throw std::invalid_argument("Invalid number of vertices.");
    }
    bool isOctagon = checkOctagon(points[0], points[1], points[2], points[3], points[4], points[5], points[6], points[7]);

    if (!isOctagon) {
        throw std::invalid_argument("Invalid points.");
    }

    this->coordinates = {points[0], points[1], points[2], points[3], points[4], points[5], points[6], points[7]};

}

template <typename T>
Octagon<T>::Octagon(Octagon<T>&& other) noexcept {
    this->coordinates[0] = std::move(other.coordinates[0]);
    this->coordinates[1] = std::move(other.coordinates[1]);
    this->coordinates[2] = std::move(other.coordinates[2]);
    this->coordinates[3] = std::move(other.coordinates[3]);
    this->coordinates[4] = std::move(other.coordinates[4]);
    this->coordinates[5] = std::move(other.coordinates[5]);
    this->coordinates[6] = std::move(other.coordinates[6]);
    this->coordinates[7] = std::move(other.coordinates[7]);
}

template <typename T>
T& Octagon<T>::operator = (const Octagon<T>& other) noexcept {
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

template <typename T>
T& Octagon<T>::operator = (Octagon<T>&& move) noexcept {
    this->coordinates[0] = std::move(move.coordinates[0]);
    this->coordinates[1] = std::move(move.coordinates[1]);
    this->coordinates[2] = std::move(move.coordinates[2]);
    this->coordinates[3] = std::move(move.coordinates[3]);
    this->coordinates[4] = std::move(move.coordinates[4]);
    this->coordinates[5] = std::move(move.coordinates[5]);
    this->coordinates[6] = std::move(move.coordinates[6]);
    this->coordinates[7] = std::move(move.coordinates[7]);

    move.coordinates[0] = Point<T>();
    move.coordinates[1] = Point<T>();
    move.coordinates[2] = Point<T>();
    move.coordinates[3] = Point<T>();
    move.coordinates[4] = Point<T>();
    move.coordinates[5] = Point<T>();
    move.coordinates[6] = Point<T>();
    move.coordinates[7] = Point<T>();

    return *this;
}

template <typename T>
bool Octagon<T>::operator == (const Octagon<T>& other) const{
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

template <typename T>
Octagon<T>::Octagon(
    const Point<T>& p1, 
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5,
    const Point<T>& p6,
    const Point<T>& p7,
    const Point<T>& p8
    ) {

    bool isOctagon = checkOctagon(p1, p2, p3, p4, p5, p6, p7, p8);

    if (!isOctagon) {
        throw std::invalid_argument("Invalid points.");
    }

    this->coordinates = {p1, p2, p3, p4, p5, p6, p7, p8};
}

template <typename T>
Point<T> Octagon<T>::geometricCenter() const noexcept{
    double center_x = 0.0;
    double center_y = 0.0;

    for (size_t i = 0; i < this->coordinates.get_size(); ++i) {
        center_x += this->coordinates[i].getX();
        center_y += this->coordinates[i].getY();
    }
    return Point<T>(center_x / 8.0, center_y / 8.0);
}

template <typename T>
double Octagon<T>::area() const noexcept {
    double sideLen = Point<T>::distance(this->coordinates[0], this->coordinates[1]);

    return 2 * std::pow(sideLen, 2) * (1 + std::sqrt(2));
}

template <typename T>
bool Octagon<T>::operator != (const Octagon<T>& other) const {
    return !(*this == other);
}

template <typename T>
Octagon<T>::operator double() const {
    double sideLen = Point<T>::distance(this->coordinates[0], this->coordinates[1]);

    return 2 * std::pow(sideLen, 2) * (1 + std::sqrt(2));
}

template <typename U>
std::istream& operator>>(std::istream& is, Octagon<U>& o) {
    is >> o.coordinates[0] >> o.coordinates[1]  >> o.coordinates[2] >> o.coordinates[3] >> o.coordinates[4] >> o.coordinates[5] >> o.coordinates[6]  >> o.coordinates[7];
    return is; 
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const Octagon<U>& o) {
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