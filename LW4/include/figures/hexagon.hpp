#pragma once

#include "figure.hpp"

template <typename T>
class Hexagon final : public Figure<T> {
public:
    Hexagon() = default;
    Hexagon(const Vector<Point<T>>& points);
    Hexagon(const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&);
    Hexagon(const Hexagon<T>& other) noexcept;
    Hexagon(Hexagon<T>&& other) noexcept;

    Hexagon& operator = (const Hexagon<T>& other) noexcept;
    Hexagon& operator = (Hexagon<T>&& move) noexcept;

    virtual ~Hexagon() = default;
    
    virtual Point<T> geometricCenter() const noexcept override;
    virtual double area() const noexcept override;


    virtual operator double() const override;

    bool operator == (const Hexagon<T>& other) const;
    bool operator != (const Hexagon<T>& other) const;

    template <typename U>
    friend std::istream& operator>>(std::istream&, Hexagon<U>&);
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Hexagon<U>&);

private:
    static bool checkHexagon(const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&) noexcept;
};