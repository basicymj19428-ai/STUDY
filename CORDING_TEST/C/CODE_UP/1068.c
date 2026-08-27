#include <stdio.h>

int main(void)
{
    int grade;
    scanf("%d", &grade);

    if(grade >= 90) {
        printf("A");
    }
    else if(grade >= 70) {
        printf("B");
    }
    else if(grade >= 40) {
        printf("C");
    }
    else
    {
        printf("D");
    }

    return 0;
}