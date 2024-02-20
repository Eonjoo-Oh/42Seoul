#include <iostream>
#include <vector>

// 야콥스탈 함수를 구현합니다.
int jacobsthal(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// 이진 탐색을 수행하는 함수입니다.
int binarySearch(const std::vector<int>& vec, int key) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // 중앙 인덱스 계산
        if (vec[mid] == key)
            return mid;
        else if (vec[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // 찾지 못한 경우
}

// pendingChain의 수를 mainChain에 야콥스탈을 이용한 이진 탐색으로 넣는 함수
void insertUsingJacobsthal(std::vector<int>& mainChain, const std::vector<int>& pendingChain) {
    for (int i = 0; i < pendingChain.size(); ++i) {
        int pos = binarySearch(mainChain, pendingChain[i]); // 이진 탐색으로 삽입 위치를 찾음
        if (pos == -1)
            mainChain.push_back(pendingChain[i]); // 삽입 위치를 찾지 못한 경우 벡터 끝에 추가
        else
            mainChain.insert(mainChain.begin() + pos, pendingChain[i]); // 삽입 위치를 찾은 경우 해당 위치에 삽입
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    std::vector<int> mainChain(arr, arr + sizeof(arr) / sizeof(arr[0]));
    int arr2[] = {2, 4, 6, 8, 10};
    std::vector<int> pendingChain(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));

    // pendingChain의 수를 mainChain에 야콥스탈을 이용한 이진 탐색으로 삽입
    insertUsingJacobsthal(mainChain, pendingChain);

    // mainChain 출력
    for (size_t i = 0; i < mainChain.size(); i++) {
        std::cout << mainChain[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}