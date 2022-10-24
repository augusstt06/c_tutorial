// 파일 입/출력
#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;
    // w = 쓰기 모드, r = 읽기 모드
    fp = fopen("output.txt", "w");

    if (fp == NULL)
    {
        printf("파일열기에 실패하였습니다. \n");
    }
    else
    {
        printf("파일열기에 성공하였습니다. \n");
    }
    fputc('H', fp);
    fputc('i', fp);
    fclose(fp);
    return 0;
}