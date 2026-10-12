#include <stdio.h> 
#include <stdlib.h>

int *solution(int money)
{
    int *result = malloc(2 * sizeof(result));

    result[0] = money / 5500;
    result[1] = money % 5500;

    return result;
}