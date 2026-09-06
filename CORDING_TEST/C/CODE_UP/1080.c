#include <stdio.h>

int main(void)
{
    int num;
    int sum = 0;
    scanf("%d", &num);

    for(int i = 0; sum <= num; i++) {
        sum += i;

        if(sum >= num) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}