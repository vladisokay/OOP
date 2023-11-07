#include "../../include/figures/pentagon.hpp"

template <typename T>
bool Pentagon<T>::checkPentagon(
    const Point<T>& p1,
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5
    
) noexcept {
    double sum_x = p1.getX() + p2.getX() + p3.getX() + p4.getX() + p5.getX();
    double sum_y = p1.getY() + p2.getY() + p3.getY() + p4.getY() + p5.getY();

    double center_x = sum_x / 5.0;
    double center_y = sum_y / 5.0;

    Point<T> center(center_x, center_y);
    double inaccuracy = 1e-1;

    double lenToP1 = Point<T>::distance(center, p1);
    double lenToP2 = Point<T>::distance(center, p2);
    double lenToP3 = Point<T>::distance(center, p3);
    double lenToP4 = Point<T>::distance(center, p4);
    double lenToP5 = Point<T>::distance(center, p5);

    // std::cout << lenToP1 << std::endl;
    // std::cout << lenToP2 << std::endl;
    // std::cout << lenToP3 << std::endl;
    // std::cout << lenToP4 << std::endl;
    // std::cout << lenToP5 << std::endl;



    if (
        std::abs(lenToP1 - lenToP2) < inaccuracy &&
        std::abs(lenToP2 - lenToP3) < inaccuracy &&
        std::abs(lenToP3 - lenToP4) < inaccuracy &&
        std::abs(lenToP4 - lenToP5) < inaccuracy
    ) {
        return true;
    }
    return false;
}

template <typename T>
Pentagon<T>::Pentagon(
    const Point<T>& p1, 
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5
    ) {
    
    bool isPentagon = checkPentagon(p1, p2, p3, p4, p5);


    if (!isPentagon) {
        throw std::invalid_argument("Invalid points.");
    }

    this->coordinates = {p1, p2, p3, p4, p5};
}

template <typename T>
Pentagon<T>::Pentagon(const Pentagon<T>& other) noexcept {
    this->coordinates[0] = other.coordinates[0];
    this->coordinates[1] = other.coordinates[1];
    this->coordinates[2] = other.coordinates[2];
    this->coordinates[3] = other.coordinates[3];
    this->coordinates[4] = other.coordinates[4];
}

template <typename T>
Pentagon<T>::Pentagon(const Vector<Point<T>>& points) {
    if (points.get_size() < 5) {
        throw std::invalid_argument("Invalid number of vertices.");
    }
    bool isPentagon = checkPentagon(points[0],
                                  points[1],
                                  points[2],
                                  points[3],
                                  points[4]);
    if (!isPentagon) {
        throw std::invalid_argument("Invalid points.");
    }

    this->coordinates = {points[0], points[1], points[2], points[3], points[4]};

}

template <typename T>
Pentagon<T>::Pentagon(Pentagon<T>&& other) noexcept {
    this->coordinates[0] = std::move(other.coordinates[0]);
    this->coordinates[1] = std::move(other.coordinates[1]);
    this->coordinates[2] = std::move(other.coordinates[2]);
    this->coordinates[3] = std::move(other.coordinates[3]);
    this->coordinates[4] = std::move(other.coordinates[4]);
}

template <typename T>
Pentagon<T>& Pentagon<T>::operator = (const Pentagon<T>& other) noexcept {
    if (this == &other) return *this;

    this->coordinates[0] = other.coordinates[0];
    this->coordinates[1] = other.coordinates[1];
    this->coordinates[2] = other.coordinates[2];
    this->coordinates[3] = other.coordinates[3];
    this->coordinates[4] = other.coordinates[4];

    return *this;

}

template <typename T>
Pentagon<T>& Pentagon<T>::operator = (Pentagon<T>&& move) noexcept {
    this->coordinates[0] = std::move(move.coordinates[0]);
    this->coordinates[1] = std::move(move.coordinates[1]);
    this->coordinates[2] = std::move(move.coordinates[2]);
    this->coordinates[3] = std::move(move.coordinates[3]);
    this->coordinates[4] = std::move(move.coordinates[4]);

    move.coordinates[0] = Point<T>();
    move.coordinates[1] = Point<T>();
    move.coordinates[2] = Point<T>();
    move.coordinates[3] = Point<T>();
    move.coordinates[4] = Point<T>();

    return *this;
}

template <typename T>
bool Pentagon<T>::operator == (const Pentagon<T>& other) const{
    return  (
               this->coordinates[0] == other.coordinates[0] &&
               this->coordinates[1] == other.coordinates[1] &&
               this->coordinates[2] == other.coordinates[2] &&
               this->coordinates[3] == other.coordinates[3] &&
               this->coordinates[4] == other.coordinates[4]);
}


template <typename T>
Point<T> Pentagon<T>::geometricCenter() const noexcept{
    double center_x = 0.0;
    double center_y = 0.0;

    for (size_t i = 0; i < this->coordinates.get_size(); ++i) {
        center_x += this->coordinates[i].getX();
        center_y += this->coordinates[i].getY();
    }

    return Point<T>(center_x / 5.0, center_y / 5.0);
}

template <typename T>
double Pentagon<T>::area() const noexcept {
    double sideLen = Point<T>::distance(this->coordinates[0], this->coordinates[1]);

    return 0.25 * (5 * sqrt(5) * pow(sideLen, 2));
}

template <typename T>
bool Pentagon<T>::operator != (const Pentagon& other) const {
    return !(*this == other);
}

template <typename T>
Pentagon<T>::operator double() const {
    double sideLen = Point<T>::distance(this->coordinates[0], this->coordinates[1]);

    return 0.25 * (5 * sqrt(5) * pow(sideLen, 2));
}

template <typename U>
std::istream& operator>>(std::istream& is, Pentagon<U>& p) {
    is >> p.coordinates[0] >> p.coordinates[1] >> p.coordinates[2] >> p.coordinates[3] >> p.coordinates[4];
    return is; 
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const Pentagon<U>& p) {
    os << p.coordinates[0] << std::endl;
    os << p.coordinates[1] << std::endl;
    os << p.coordinates[2] << std::endl;
    os << p.coordinates[3] << std::endl;
    os << p.coordinates[4] << std::endl; 

    return os;
}