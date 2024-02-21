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

// 이진 탐색을 사용하여 mainChain에 값을 삽입하는 함수입니다.
void insertUsingJacobsthal(std::vector<int>& mainChain, int value) {
    int low = 0;
    int high = mainChain.size() - 1;

    while (low <= high) {
        int mid = low + jacobsthal(high - low); // 야콥스탈 함수로 스텝 크기 결정
		std::cout << "mid : " << mid << std::endl;
		std::cout << "jacob: " << mid - low << std::endl;
        if (value < mainChain[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    // 삽입 위치에 값을 삽입합니다.
    mainChain.insert(mainChain.begin() + low, value);
}

int main() {
    // mainChain과 pendingChain을 초기화합니다.
    std::vector<int> mainChain;
	int arr2[] = {2, 1, 6, 8, 10};
    std::vector<int> pendingChain(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));

    // pendingChain의 각 요소를 mainChain에 삽입합니다.
    for (size_t i = 0; i < pendingChain.size(); ++i) {
        insertUsingJacobsthal(mainChain, pendingChain[i]);
    }

    // 정렬된 mainChain을 출력합니다.
    std::cout << "Sorted mainChain: ";
    for (size_t i = 0; i < mainChain.size(); ++i) {
        std::cout << mainChain[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
