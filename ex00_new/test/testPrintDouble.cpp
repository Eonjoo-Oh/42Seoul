#include <iostream>
#include <sstream>


int main() {
    std::string input = "2143.0123";
    double doubleValue;

    std::istringstream iss(input);
    iss >> doubleValue;

    // Output the double value without modifying precision
    std::cout << "double : " << doubleValue << std::endl;

    return 0;
}