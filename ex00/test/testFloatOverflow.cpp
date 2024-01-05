#include <iostream>
#include <sstream>

int main() {
    std::string floattype = "1000000";
    std::istringstream iss(floattype);
    float a;

    iss >> a;
    if (iss.fail()) {
        std::cout << "Conversion failed." << std::endl;
    } else {
        std::cout << "Float value: " << a << std::endl;
    }

    return 0;
}