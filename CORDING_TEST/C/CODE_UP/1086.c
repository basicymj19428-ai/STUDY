#include <stdio.h>

int main(void)
{
    long long int w, h, b;
    double result;
    scanf("%lld%lld%lld", &w, &h, &b);

    result = (double)(w * h * b) / (1024 * 1024 * 8);
    printf("%.2lf MB\n", result);

    return 0;
}