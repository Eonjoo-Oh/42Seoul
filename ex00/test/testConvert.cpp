#include <iostream>
#include <sstream>

int convertStringToInt(const std::string& str) {
    std::istringstream iss(str);
    int result;
    iss >> result;
    return result;
}

int main() {
    std::string str = "21474836490";
    try {
        int intValue = convertStringToInt(str);
        std::cout << "Converted value: " << intValue << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Conversion failed: " << e.what() << std::endl;
    }

    return 0;
}