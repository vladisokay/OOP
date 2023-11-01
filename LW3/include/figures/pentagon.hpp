#pragma once

#include "figure.hpp"

class Pentagon: public Figure {
public:
    Pentagon() = default;
    Pentagon(const Vector<Point>& points);
    Pentagon(const Point&, const Point&, const Point&, const Point&, const Point&);
    Pentagon(const Pentagon& other) noexcept;
    Pentagon(Pentagon&& other) noexcept;

    Pentagon& operator = (const Pentagon& other) noexcept;
    Pentagon& operator = (Pentagon&& move) noexcept;

    virtual ~Pentagon() = default;
    
    virtual Point geometricCenter() const noexcept override;
    virtual double area() const noexcept override;


    virtual operator double() const override;

    bool operator == (const Pentagon& other) const;
    bool operator != (const Pentagon& other) const;

    friend std::istream& operator>>(std::istream&, Pentagon&);
    friend std::ostream& operator<<(std::ostream&, const Pentagon&);

private:
    bool checkPentagon(const Point&, const Point&, const Point&, const Point&, const Point&) noexcept;
};