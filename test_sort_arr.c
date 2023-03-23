#include <stdio.h>
#include "push_swap.h"

int main(void)
{
    int arr[10] = {3,2,5,4,7,1,9,8,0,6};
    sort_arr(arr, 10);
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }

    return (0);
}