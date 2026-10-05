#include <stdio.h>

int solution(int age)
{
    scanf("%d", &age);

    int birth_year = 2022 - age + 1;

    return birth_year;
}