#include <iostream>
#include <sstream>

int main() {
    std::string str = "3.14f";
    float floatValue;

	if (str[str.length() - 1] == 'f')
		str.erase(str.length() - 1);
    std::istringstream iss(str);

	iss >> floatValue;
    if (!iss.fail()) {
        // 변환 성공
        std::cout << "Float value: " << floatValue << std::endl;
    } else {
        // 변환 실패
        std::cout << "Conversion failed." << std::endl;
    }
	int	intValue = static_cast<int>(floatValue);
	std::cout << "Int value: " << intValue << std::endl;

    return 0;
}