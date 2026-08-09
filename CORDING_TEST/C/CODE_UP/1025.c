#include <stdio.h>

int main(void)
{
    int word[5];
    scanf("%1d%1d%1d%1d%1d", &word[0], &word[1], &word[2], &word[3], &word[4]);

    printf("[%d]\n", word[0] * 10000);
    printf("[%d]\n", word[1] * 1000);
    printf("[%d]\n", word[2] * 100);
    printf("[%d]\n", word[3] * 10);
    printf("[%d]\n", word[4]);

    return 0;
}