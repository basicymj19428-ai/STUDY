#include <stdio.h>

int main(void)
{
    int num1, num2, num3;
    scanf("%d%d%d", &num1, &num2, &num3);
    
    printf("%s\n", (num1 % 2) == 0 ? "even" : "odd");
    printf("%s\n", (num2 % 2) == 0 ? "even" : "odd");
    printf("%s\n", (num3 % 2) == 0 ? "even" : "odd");

    return 0;
}