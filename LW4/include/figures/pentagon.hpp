#pragma once

#include "figure.hpp"

template <typename T>
class Pentagon: public Figure<T> {
public:
    Pentagon() = default;
    Pentagon(const Vector<Point<T>>& points);
    Pentagon(const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&);
    Pentagon(const Pentagon<T>& other) noexcept;
    Pentagon(Pentagon<T>&& other) noexcept;

    Pentagon& operator = (const Pentagon<T>& other) noexcept;
    Pentagon& operator = (Pentagon<T>&& move) noexcept;

    virtual ~Pentagon() = default;
    
    Point<T> geometricCenter() const noexcept override;
    virtual double area() const noexcept override;


    virtual operator double() const override;

    bool operator == (const Pentagon<T>& other) const;
    bool operator != (const Pentagon<T>& other) const;

    template <typename U>
    friend std::istream& operator>>(std::istream&, Pentagon<U>&);
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Pentagon<U>&);

private:
    bool checkPentagon(const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&) noexcept;
};