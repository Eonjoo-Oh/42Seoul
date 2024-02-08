#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>

int main(int argc, char **argv) {
    // 벡터를 초기화합니다.
    std::vector<int> numbers;

    // 프로그램 인자가 없으면 종료합니다.
    if (argc <= 1) {
        std::cerr << "No arguments provided." << std::endl;
        return 1;
    }

    // 각 문자열을 순회하면서 처리합니다.
    for (int i = 1; i < argc; ++i) {
        // std::istringstream을 사용하여 문자열을 스트림으로 변환합니다.
        std::istringstream iss(argv[i]);
        int num;
        // 문자열을 정수로 변환하고 변환이 성공했는지 확인합니다.
        if (!(iss >> num)) {
            // 변환이 실패한 경우 오류를 출력하고 프로그램을 종료합니다.
            std::cerr << "Error: Non-integer element found: " << argv[i] << std::endl;
            return 1;
        }
        // 정수를 벡터에 추가합니다.
        numbers.push_back(num);
    }

    // 벡터에 저장된 정수들을 출력합니다.
    std::cout << "Numbers:";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    return 0;
}