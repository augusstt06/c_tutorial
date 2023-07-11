#include <stdio.h>

// 기본적인 이진탐색 (정렬된 배열에 한하여 사용이 가능하다.)
// 시간 복잡도
// n개의 데이터를 탐색시, 최대 log2n
int BinarySearch(int arr[], int length, int target)
{
    int first = 0;
    int last = length - 1;
    int mid;

    while (first <= last)
    {
        mid = (first + last) / 2;
        if (target == arr[mid])
        {
            return mid;
        }
        else
        {
            if (target < arr[mid])
                last = mid - 1;
            else
                first = mid + 1;
        }
    }
    return -1;
}

int main(void)
{
    int array[] = {1, 3, 6, 7};
    int index;
    index = BinarySearch(array, sizeof(array) / sizeof(int), 3);

    if (index == -1)
        printf("검색에 실패했습니다. \n");
    else
        printf("타겟은 배열의 %d번째 인덱스에 있습니다. \n", index);

    return 0;
}