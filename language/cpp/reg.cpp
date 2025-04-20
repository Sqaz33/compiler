#include <regex>
#include <iostream>

int main() {
    const std::regex r("-?\\d+.?\\d*");
    std::cout << std::boolalpha << std::regex_match("123.0", r) << ' ' <<
                                   std::regex_match("1.0", r) << std::endl;
} 