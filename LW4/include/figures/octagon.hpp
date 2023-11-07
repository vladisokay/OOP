#pragma once

#include "figure.hpp"

template <typename T>
class Octagon : public Figure<T> {
public:
    Octagon() = default;
    Octagon(const Vector<Point<T>>& points);
    Octagon(const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&);
    Octagon(const Octagon& other) noexcept;
    Octagon(Octagon&& other) noexcept;

    T& operator = (const Octagon<T>& other) noexcept;
    T& operator = (Octagon<T>&& move) noexcept;

    virtual ~Octagon() = default;
    
    virtual Point<T> geometricCenter() const noexcept override;
    virtual double area() const noexcept override;

    virtual operator double() const override;

    bool operator == (const Octagon<T>& other) const;
    bool operator != (const Octagon<T>& other) const;

    template <typename U>
    friend std::istream& operator>>(std::istream&, Octagon<U>&);
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Octagon<U>&);

private:
    bool checkOctagon(const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&, 
        const Point<T>&) noexcept;

};