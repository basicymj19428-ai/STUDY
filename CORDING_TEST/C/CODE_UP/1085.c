#include <stdio.h>

int main(void)
{
    long long int h, b, s, c;
    double result = 0;
    scanf("%lld%lld%lld%lld", &h, &b, &s, &c);

    result = (double)(h * b * s * c) / (8 * 1024 * 1024);

    printf("%.1lf MB\n", result);

    return 0;
}