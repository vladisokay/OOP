#pragma once

#include "figure.hpp"

class Hexagon final : public Figure {
private:
    Point _topOne;
    Point _topTwo;
    Point _topThree;
    Point _topFour;
    Point _topFive;
    Point _topSix;

public:
    Hexagon() = default;
    Hexagon(const Point&, const Point&, const Point&, const Point&, const Point&, const Point&);
    Hexagon(const Hexagon& other) noexcept;
    Hexagon(Hexagon&& other) noexcept;

    Hexagon& operator = (const Hexagon& other) noexcept;
    Hexagon& operator = (Hexagon&& move) noexcept;

    virtual ~Hexagon() = default;
    
    virtual Point geometricCenter() const noexcept override;
    virtual double area() const noexcept override;
    static double angle(const Point& p1, const Point& p2, const Point& p3) noexcept;

    virtual operator double() const override;

    bool operator == (const Hexagon& other) const;
    bool operator != (const Hexagon& other) const;

    friend std::istream& operator>>(std::istream&, Hexagon&);
    friend std::ostream& operator<<(std::ostream&, const Hexagon&);

private:
    static bool checkHexagon(const Point&, const Point&, const Point&, const Point&, const Point&, const Point&) noexcept;

};