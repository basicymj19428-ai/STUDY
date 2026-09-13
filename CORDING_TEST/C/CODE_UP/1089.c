#include <stdio.h>

int main(void)
{
    int a, d, n;
    int result = 0;
    scanf("%d%d%d", &a, &d, &n);

    // for(int i = a; i <= n; i ++) {
    //     result = a + (n - 1) * d;
    // }

    result = a + (n - 1) * d;

    printf("%d\n", result);

    return 0;
}