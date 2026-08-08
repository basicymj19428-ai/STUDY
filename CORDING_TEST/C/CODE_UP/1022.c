#include <stdio.h>

int main(void)
{
    char sentenc[2000];
    fgets(sentenc, sizeof(sentenc), stdin);

    printf("%s", sentenc);

    return 0;
}