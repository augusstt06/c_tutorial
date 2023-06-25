#include <stdio.h>
// 앞에서 부터 순서대로 탐색을 하는 알고리즘
// 시간 복잡도
// n개의 데이터를 탐색할때, 최소 1, 최대 n의 시간 복잡도를 가진다.
int LinearSearch(int arr[], int length, int target)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int array[] = {2, 3, 1, 6};
    int index;

    index = LinearSearch(array, sizeof(array) / sizeof(index), 3);

    if (index == -1)
        printf("검색을 실패하였습니다. \n");

    else
        printf("배열의 %d번째 인덱스에 타겟이 있습니다. \n", index);
    return 0;
}