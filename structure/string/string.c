// char(영어) = 1 byte
// 한글 = 2 byte

#include <stdio.h>

int main(void)
{
    char input[1001];
    gets(input);
    int count = 0;
    while (input[count] != '\0')
    {
        count++;
    }
    printf("입력한 문자열의 길이 : %d\n", count);
    printf("입력한 문자열 : %s", input);
    return 0;
}