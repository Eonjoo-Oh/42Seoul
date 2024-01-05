#include <iostream>
#include <sstream>

#include <iostream>
#include <sstream>
#include <iomanip>

#include <iostream>
#include <sstream>

int main() {
    std::string str = "3";
    float floatValue;

    // istringstream을 사용하여 정수부분만 추출
    int intValue;
    std::istringstream intStream(str);
    if (!(intStream >> intValue).fail()) {
        // 정수부분을 부동 소수점으로 변환하여 출력
        floatValue = static_cast<float>(intValue);
        std::cout << "Float value: " << floatValue << std::endl;
    } else {
        // 변환 실패
        std::cout << "Conversion failed." << std::endl;
    }

    return 0;
}