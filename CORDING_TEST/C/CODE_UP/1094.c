#include <stdio.h>

int main(void)
{
    int n;
    int count[10001];

    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);

        count[n-i] = num;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}