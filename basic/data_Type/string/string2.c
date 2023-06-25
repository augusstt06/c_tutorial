#include <stdio.h>
#include <string.h>

int main(void)
{
    // char input[5] = "TEST";
    // printf("문자열 길이 : %d\n", strlen(input));

    char input[10] = "C언어";
    char result[10] = "테스트";

    strcpy(result, input);
    printf("문자열 복사 : %s\n", result);
    return 0;
}
