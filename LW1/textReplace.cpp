#include "textReplace.h"

std::string textReplace(std::string text, int n, char old_value, char new_value) {

    if (n <= 0) {
        return text;
    }

    int countOldValue = 0;
    for (char &currentSymbol : text) {
        if (currentSymbol == old_value) {
            ++countOldValue;
        }
    }

    if (n < countOldValue) {
        return text;
    }

    int count = 0;
    for (char &currentSymbol : text) {
        if (currentSymbol == old_value) {
            ++count;
            if (count % n == 0) {
                currentSymbol = new_value;
            }
        }
    }

    return text;
}