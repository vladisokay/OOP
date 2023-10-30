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


    Vector<Figure*> figures_vector;

    // Pentagon* Pentagon_ptr = new Pentagon(Point(0, 10),
    //                                       Point(26.181, 6.181),
    //                                       Point(16.180, -8.090),
    //                                       Point(-16.180, -8.090),
    //                                       Point(-26.181, 6.181) );


    
    Octagon* Octagon_ptr = new Octagon(p1, p2, p3, p4, p5, p6, p7, p8);

    figures_vector.push_back(static_cast<Figure*>(Octagon_ptr));
    // figures_vector.push_back(static_cast<Figure*>(Pentagon_ptr));
   


    // figures_vector.printGeometricCenter();
    // std::cout << std::endl;
    // figures_vector.printArea();

    Hexagon* Hexagon_ptr = new Hexagon(pp1, pp2, pp3, pp4, pp5, pp6);

    figures_vector.push_back(static_cast<Figure*>(Hexagon_ptr));


    std::cout << std::endl << "Total area" << std::endl;
    std::cout << figures_vector.calculateTotalArea() << std::endl;

    figures_vector.erase(0);

    // figures_vector.printGeometricCenter();
    // figures_vector.printArea();
    // figures_vector.erase(0);

    // std::cout << std::endl << "Total area" << std::endl;
    // std::cout << figures_vector.calculateTotalArea() << std::endl;



}