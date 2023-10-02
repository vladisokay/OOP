#include "include/decimal.h"

int main() {
    Decimal x("123");
    Decimal z("321");

    Decimal s(x + z);

    std::cout << s << std::endl;

    return 0;
}