#include "string.hpp"
#include <iostream>

int main() {
    String first("First");
    String second("Second");

    String combined = first + second;
    std::cout << combined << '\n';

    std::cout << "Enter a word: ";
    String word;
    std::cin >> word;

    std::cout << word << '\n';

    return 0;
}
