#include <iostream>
#include <vector>

void	merge(std::vector<int> &v, int start, int end)
{

}

void	partition(std::vector<int> &v, int start, int end)
{
	int	mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		partition(v, start, mid);
		partition(v, mid + 1, end);
		merge(v, start, end);
	}
	
}