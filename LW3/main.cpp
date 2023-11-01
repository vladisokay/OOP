#include <iostream>

#include "src/figures/point.cpp"

#include "include/figures/point.hpp"
#include "include/figures/pentagon.hpp"
#include "include/figures/hexagon.hpp"
#include "include/figures/octagon.hpp"

int main() {

    // Octagon coordinates. 
    Point p1(10, 10);
    Point p2(p1.getX() - (1 + std::sqrt(2)), p1.getY() + 1);
    Point p3(p2.getX() - 1, p2.getY() + 1 + std::sqrt(2));
    Point p4(p3.getX() + 1, p3.getY() + (1 + std::sqrt(2)));
    Point p5(p4.getX() + 1 + std::sqrt(2), p4.getY() + 1);
    Point p6(p5.getX() + 1 + std::sqrt(2), p5.getY() - 1);
    Point p7(p6.getX() + 1, p6.getY() - (1 + std::sqrt(2)));
    Point p8(p7.getX() - 1, p7.getY() - (1 + std::sqrt(2)));
    // Hexagon coordinates.
    Point pp1(1, 4);
    Point pp2(-3, 0);
    Point pp3(std::sqrt(3), 3 - std::sqrt(3));
    Point pp4(-std::sqrt(3), 3 + std::sqrt(3));
    Point pp5(-2 - std::sqrt(3), 1 + std::sqrt(3));
    Point pp6(-2 + std::sqrt(3), 1 - std::sqrt(3));
    // Pentagon coordinates.
    Point ppp1(0, 1);
    Point ppp2(0.95106, 0.30902);
    Point ppp3(0.58779, -0.80902);
    Point ppp4(-0.58779, -0.80902);
    Point ppp5(-0.95106, 0.30902);

    Point t1(1, 2);
    Point t2(1.95106, 1.30902);
    Point t3(1.58779, 0.19098);
    Point t4(0.41221, 0.19098);
    Point t5(0.04894, 1.30902);



    Vector<Figure*> figures_vector;



    
    Octagon* octagonPtr = new Octagon(p1, p2, p3, p4, p5, p6, p7, p8);
    Hexagon* hexagonPtr = new Hexagon(pp1, pp2, pp3, pp4, pp5, pp6);
    Pentagon* pentagonPtr = new Pentagon(ppp1, ppp2, ppp3, ppp4, ppp5);
    Pentagon* tPtr = new Pentagon(t1, t2, t3, t4, t5);

    figures_vector.push_back(static_cast<Figure*>(octagonPtr));
    figures_vector.push_back(static_cast<Figure*>(hexagonPtr));
    figures_vector.push_back(static_cast<Figure*>(pentagonPtr));
    figures_vector.push_back(static_cast<Figure*>(tPtr));

    // double square = static_cast<double>(Hexagon(pp1, pp2, pp3, pp4, pp5, pp6));

    // std::cout << "GEOM CENTR TEST" << std::endl;
    // std::cout << square << std::endl;


    std::cout << std::endl << "Total area" << std::endl;
    std::cout << figures_vector.calculateTotalArea() << std::endl;

    figures_vector.erase(0);

    figures_vector.printGeometricCenter();
    figures_vector.printArea();
    figures_vector.erase(0);

    std::cout << std::endl << "Total area" << std::endl;
    std::cout << figures_vector.calculateTotalArea() << std::endl;



}