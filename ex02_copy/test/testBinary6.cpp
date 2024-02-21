#include <iostream>
#include <vector>

void binaryInsertSort(std::vector<int> &arr, int right) {
    for (int i = 1; i <= right; ++i) {
        int key = arr[i];
        int left = 0;

        // 이진 탐색을 통해 key가 삽입될 위치를 찾습니다.
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }

        // key를 삽입될 위치에 삽입합니다.
        for (int j = i - 1; j >= left; --j) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}

int main() {
    std::vector<int> arr = {5, 3, 8, 2, 1, 9, 4, 7, 6};
    std::cout << "Before sorting: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int right = arr.size() - 1;
    binaryInsertSort(arr, right);

    std::cout << "After sorting: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}