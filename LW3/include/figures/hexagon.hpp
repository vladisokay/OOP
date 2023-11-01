#pragma once

#include "figure.hpp"

class Hexagon final : public Figure {
public:
    Hexagon() = default;
    Hexagon(const Vector<Point>& points);
    Hexagon(const Point&, const Point&, const Point&, const Point&, const Point&, const Point&);
    Hexagon(const Hexagon& other) noexcept;
    Hexagon(Hexagon&& other) noexcept;

    Hexagon& operator = (const Hexagon& other) noexcept;
    Hexagon& operator = (Hexagon&& move) noexcept;

    virtual ~Hexagon() = default;
    
    virtual Point geometricCenter() const noexcept override;
    virtual double area() const noexcept override;


    virtual operator double() const override;

    bool operator == (const Hexagon& other) const;
    bool operator != (const Hexagon& other) const;

    friend std::istream& operator>>(std::istream&, Hexagon&);
    friend std::ostream& operator<<(std::ostream&, const Hexagon&);

private:
    static bool checkHexagon(const Point&, const Point&, const Point&, const Point&, const Point&, const Point&) noexcept;
};