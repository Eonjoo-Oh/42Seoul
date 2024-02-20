#include <iostream>
#include <vector>

/*
int main()
{
	int	targetValue = 11;

	int arr2[] = {1, 2, 6, 8};
    std::vector<int> mainChain(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    int left = 0;
    int right = mainChain.size() - 1;
    int insertPosition = -1; // targetValue가 삽입될 위치

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (mainChain[mid] == targetValue)
        {
            // 중복된 값이 있을 경우 mid의 왼쪽에 삽입합니다.
            insertPosition = mid;
            break;
        }
        else if (mainChain[mid] < targetValue)
        {
            left = mid + 1;
        }
        else
        {
            // mid의 왼쪽에 삽입되어야 하므로 insertPosition을 갱신합니다.
            insertPosition = mid;
            right = mid - 1;
        }
    }

    // targetValue를 삽입합니다.
    mainChain.insert(mainChain.begin() + insertPosition, targetValue);

	for(size_t i = 0; i < mainChain.size(); i++)
	{
		std::cout << mainChain[i] << " ";
	}
}
*/
/*
int main()
{
	int arr2[] = {1, 2, 6, 8};
	std::vector<int> mainChain(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));

	int low = 0; high = mainChain.size() - 1; 

}
*/
int main() {
    int targetValue = 6;

    int arr2[] = {1, 2, 6, 8, 10};
    std::vector<int> mainChain(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));

    // 이진 탐색을 사용하여 삽입할 위치를 찾습니다.
    int left = 0;
    int right = mainChain.size();
    int insertPosition = -1; // targetValue가 삽입될 위치

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (mainChain[mid] <= targetValue) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    // 삽입 위치를 찾은 후에 targetValue를 삽입합니다.
    mainChain.insert(mainChain.begin() + left, targetValue);

    // 결과 출력
    for (size_t i = 0; i < mainChain.size(); ++i) {
        std::cout << mainChain[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}