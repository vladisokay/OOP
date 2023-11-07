#include <iostream>
#include <memory>

#include "src/figures/point.cpp"

#include "include/figures/point.hpp"
#include "include/figures/pentagon.hpp"
#include "include/figures/hexagon.hpp"
#include "include/figures/octagon.hpp"

#include "src/figures/pentagon.cpp"
#include "src/figures/hexagon.cpp"
#include "src/figures/octagon.cpp"

using point = Point<double>;
using pentagon = Pentagon<double>;
using hexagon = Hexagon<double>;
using octagon = Octagon<double>;


int main() {

    Vector<std::shared_ptr<Figure<double>>> v;


    // Octagon coordinates. 

    Point<double> p1(10, 10);
    Point<double> p2(p1.getX() - (1 + std::sqrt(2)), p1.getY() + 1);
    Point<double> p3(p2.getX() - 1, p2.getY() + 1 + std::sqrt(2));
    Point<double> p4(p3.getX() + 1, p3.getY() + (1 + std::sqrt(2)));
    Point<double> p5(p4.getX() + 1 + std::sqrt(2), p4.getY() + 1);
    Point<double> p6(p5.getX() + 1 + std::sqrt(2), p5.getY() - 1);
    Point<double> p7(p6.getX() + 1, p6.getY() - (1 + std::sqrt(2)));
    Point<double> p8(p7.getX() - 1, p7.getY() - (1 + std::sqrt(2)));
    // Hexagon coordinates.
    Point<double> pp1(1, 4);
    Point<double> pp2(-3, 0);
    Point<double> pp3(std::sqrt(3), 3 - std::sqrt(3));
    Point<double> pp4(-std::sqrt(3), 3 + std::sqrt(3));
    Point<double> pp5(-2 - std::sqrt(3), 1 + std::sqrt(3));
    Point<double> pp6(-2 + std::sqrt(3), 1 - std::sqrt(3));
    // Pentagon coordinates.
    Point<double> ppp1(0, 1);
    Point<double> ppp2(0.95106, 0.30902);
    Point<double> ppp3(0.58779, -0.80902);
    Point<double> ppp4(-0.58779, -0.80902);
    Point<double> ppp5(-0.95106, 0.30902);

    Point<double> t1(1, 2);
    Point<double> t2(1.95106, 1.30902);
    Point<double> t3(1.58779, 0.19098);
    Point<double> t4(0.41221, 0.19098);
    Point<double> t5(0.04894, 1.30902);

    std::shared_ptr<pentagon> pnt1 = std::make_shared<pentagon>(ppp1, ppp2, ppp3, ppp4, ppp5);
    std::shared_ptr<pentagon> pnt2 = std::make_shared<pentagon>(t1, t2, t3, t4, t5);
    std::shared_ptr<hexagon> hxg1 = std::make_shared<hexagon>(pp1, pp2, pp3, pp4, pp5, pp6);
    std::shared_ptr<octagon> oct1 = std::make_shared<octagon>(p1, p2, p3, p4, p5, p6, p7, p8);

    std::shared_ptr<Figure<double>> pPtr1 = std::static_pointer_cast<Figure<double>>(pnt1);
    std::shared_ptr<Figure<double>> pPtr2 = std::static_pointer_cast<Figure<double>>(pnt2);
    std::shared_ptr<Figure<double>> hPtr1 = std::static_pointer_cast<Figure<double>>(hxg1);
    std::shared_ptr<Figure<double>> oPtr1 = std::static_pointer_cast<Figure<double>>(oct1);

    v = {pPtr1, pPtr2, hPtr1, oPtr1};

    double totalArea = pnt1->area() + pnt2->area() + hxg1->area() + oct1->area();


    std::cout << "Total Area - " << totalArea << std::endl;







    // std::cout << std::endl << "Total area" << std::endl;
    // v.printAllAreas();
    // std::cout << v.get_size() << std::endl;
    // v.erase(0);
    // std::cout<< v.get_size() << std::endl;

    // std::cout << std::endl << "Total area" << std::endl;
    // v.printAllAreas();



}