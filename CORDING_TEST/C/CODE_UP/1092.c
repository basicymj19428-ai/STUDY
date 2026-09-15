#include <stdio.h> 

int main(void)
{
    int a, b, c;
    int same = 1;

    scanf("%d%d%d", &a, &b, &c);
    for(int i = 2; ; i++) {
        if(i % a == 0 && i % b == 0 && i % c == 0) {
            same = i;
            break;
        }
    }

    printf("%d\n", same);

    return 0;
}