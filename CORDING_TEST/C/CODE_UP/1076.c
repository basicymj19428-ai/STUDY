#include <stdio.h>

int main(void)
{
    char alphabet;
    scanf("%c", &alphabet);

    for(int i = 97; i <= alphabet; i++) {
        printf("%c ", i);
    }

    return 0;
}