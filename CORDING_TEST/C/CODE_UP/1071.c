#include <stdio.h>

void print_until_zero();
int main(void)
{
    print_until_zero();
    return 0;
}

void print_until_zero()
{
    int num;
    scanf("%d", &num);

    if(num == 0) {
        return;
    }
    printf("%d\n", num);
    print_until_zero();
}