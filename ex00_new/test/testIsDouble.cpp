#include <iostream>
#include <sstream>
#include <iomanip>

int main() {
    double doubleValue = 2143.0123;

    // 부동 소수점 값을 문자열로 변환
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(15) << doubleValue;  // 조절이 필요한 경우 setprecision 사용
    std::string doubleString = oss.str();

    // 문자열을 부동 소수점으로 다시 변환
    std::istringstream iss(doubleString);
    double convertedValue;
    iss >> convertedValue;

    // 결과 출력
    std::cout << "Original double : " << doubleValue << std::endl;
    std::cout << "Converted double: " << convertedValue << std::endl;

    return 0;
}