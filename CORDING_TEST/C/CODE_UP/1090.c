#include <stdio.h>

int main(void)
{
    int a, r, n;

    scanf("%d%d%d", &a, &r, &n);
    long long int result = a;

    for(int i = 1; i < n; i++) {
        result *= r;
    }

    printf("%lld\n", result);

    return 0; 
}