#include "textReplace.h"

std::string textReplace(std::string const &text, int n, char old_value, char new_value) {

    std::string result = text;

    if (n <= 0) {
        return text;
    }

    int count = 0;
    for (char &currentSymbol : result) {
        if (currentSymbol == old_value) {
            ++count;
            if (count % n == 0) {
                currentSymbol = new_value;
            }
        }
    }

    return result;
}