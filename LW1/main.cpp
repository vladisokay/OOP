#include "textReplace.h"

int main() {
    std::string text;
    int n;
    char old_value, new_value;

    std::getline(std::cin, text);
    std::cin >> n >> old_value >> new_value;

    std::string result = textReplace(text, n, old_value, new_value);
    std::cout << result << '\n';

    return 0;
}