#pragma once

#include "figure.hpp"

class Pentagon: public Figure {
private:
    Point _topOne;
    Point _topTwo;
    Point _topThree;
    Point _topFour;
    Point _topFive;
public:
    Pentagon() = default;
    Pentagon(const Point&, const Point&, const Point&, const Point&, const Point&);
    Pentagon(const Pentagon& other) noexcept;
    Pentagon(Pentagon&& other) noexcept;

    Pentagon& operator = (const Pentagon& other) noexcept;
    Pentagon& operator = (Pentagon&& move) noexcept;

    virtual ~Pentagon() = default;
    
    virtual Point geometricCenter() const noexcept override;
    virtual double area() const noexcept override;
    static double angle(const Point& p1, const Point& p2, const Point& p3) noexcept;

    virtual operator double() const override;

    bool operator == (const Pentagon& other) const;
    bool operator != (const Pentagon& other) const;

    friend std::istream& operator>>(std::istream&, Pentagon&);
    friend std::ostream& operator<<(std::ostream&, const Pentagon&);

private:
    static bool checkPentagon(const Point&, const Point&, const Point&, const Point&, const Point&) noexcept;

};