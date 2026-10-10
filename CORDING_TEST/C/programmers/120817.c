#include <stdio.h>

double solution(int numbers[], int numbers_len)
{
    int sum = 0;

    for(int i = 0; i < numbers_len; i++) {
        sum += numbers[i];
    }

    return ((double)sum / (double)numbers_len);
}