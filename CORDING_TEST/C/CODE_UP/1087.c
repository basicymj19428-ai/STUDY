#include <stdio.h>

int main(void)
{
    int num;
    int sum = 0;
    scanf("%d", &num);

    for(int i = 1; sum < num; i++) {
        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}