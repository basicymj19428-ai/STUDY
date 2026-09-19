#include <stdio.h>

int main(void)
{
    int n;
    int count[24] = {0};
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        count[num]++;
    }

    for(int i = 1; i < 24; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}