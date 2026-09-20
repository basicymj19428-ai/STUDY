#include <stdio.h>

int main(void)
{
    int n;
    int small;
    int count[10001];
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        count[i] = num;
    }

    small = count[0];
    for(int i = 1; i < n; i++) {
        small = (small < count[i]) ? small : count[i];
    }

    printf("%d\n", small);
    return 0;
}