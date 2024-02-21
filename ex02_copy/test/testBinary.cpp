#include <iostream>
#include <vector>

// 야콥스탈 수열을 계산하는 함수
int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// 야콥스탈을 이용한 이진 탐색의 스텝 크기 계산 함수
int jacobsthalBinarySearchStep(int idx) {
    int n = 0;
    while (jacobsthal(n) < idx) {
        n++;
    }
    return jacobsthal(n - 1);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    std::vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    int target = 4;

    // 이진 탐색 스텝 크기 계산
    int step = jacobsthalBinarySearchStep(target);

    std::cout << "Step size: " << step << std::endl;

    return 0;
}
