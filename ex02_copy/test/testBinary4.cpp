
아래는 야콥스탈과 이진 탐색을 결합하여 주어진 조건에 맞게 수정된 코드입니다.

cpp
Copy code
void PmergeMe::BinaryInsertSort(std::vector<int> &mainChain, std::vector<int> &pendingChain)
{
    // pendingChain의 첫 번째 요소를 mainChain에 이진 탐색을 통해 삽입합니다.
    // mainChain이 정렬되어 있어야 합니다.
    for (size_t i = 0; i < pendingChain.size(); ++i)
    {
        int numToInsert = pendingChain[i];

        // 이진 탐색을 수행하여 numToInsert를 mainChain에 삽입할 위치를 찾습니다.
        int left = 0;
        int right = mainChain.size() - 1;
        int insertIdx = -1; // 삽입할 위치의 인덱스

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (numToInsert < mainChain[mid])
            {
                right = mid - 1;
                insertIdx = mid; // 삽입 위치가 갱신될 때마다 저장
            }
            else
            {
                left = mid + 1;
            }
        }

        // 삽입 위치가 정해졌을 때, 해당 위치에 numToInsert를 삽입합니다.
        if (insertIdx != -1)
        {
            mainChain.insert(mainChain.begin() + insertIdx, numToInsert);
        }
        else
        {
            // insertIdx가 -1이라면 numToInsert보다 모든 요소가 크므로 맨 뒤에 삽입합니다.
            mainChain.push_back(numToInsert);
        }
    }
}