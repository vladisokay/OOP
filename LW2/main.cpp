#include "include/decimal.h"

int main() {
    Decimal d;
    Decimal d1("123");
    Decimal d2("456243");
    Decimal d3 = d1;

    std::cout << "d is " << d << std::endl;
    std::cout << "d1 is " << d1 << std::endl;
    std::cout << "d2 is " << d2 << std::endl;
    std::cout << "d3 is " << d3 << std::endl;

    std::cout << std::endl;


    std::cout << "d1 + d3 is " << d1 + d3 << std::endl;
    std::cout << "d1 + d2 is " << d1 + d2 << std::endl;
    std::cout << "d2 - d1 is " << d2 - d1 << std::endl;

    std::cout << std::endl;

    std::cout << "d2 > d1 is " << (d2 > d1) << std::endl;
    std::cout << "d2 < d1 is " << (d2 < d1) << std::endl;
    std::cout << "d1 <= d2 is " << (d1 <= d2) << std::endl;
    std::cout << "d2 >= d1 is " << (d2 >= d1) << std::endl;
    std::cout << "d3 == d1 is " << (d3 == d1) << std::endl;
    std::cout << "d3 != d1 is " << (d3 != d1) << std::endl;

    std::cout << std::endl;

    ++d1;
    std::cout << "++d1 is " << d1 << std::endl;
    --d1;
    std::cout << "--d1 is " << d1 << std::endl;
    d1++;
    std::cout << "++d1 is " << d1 << std::endl;
    d1--;
    std::cout << "++d1 is " << d1 << std::endl;

    std::cout << std::endl;

    d1.print();
    d2.print();
    d3.print();

    
    return 0;
}