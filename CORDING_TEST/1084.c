#include <stdio.h>

int main(void)
{
    int num1, num2, num3;
    scanf("%d%d%d", &num1, &num2, &num3);

    for(int i = 0; i < num1; i++) {
        for(int j = 0; j < num2; j++) {
            for(int k = 0; k < num3; k++) {
                printf("%d %d %d\n", i, j, k);
            }
        }
    }

    printf("%d\n", num1 * num2 * num3);

    return 0;

}