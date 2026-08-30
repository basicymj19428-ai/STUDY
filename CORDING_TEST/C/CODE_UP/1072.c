#include <stdio.h>

void print_num(int count);

int main()
{
    int n;
    scanf("%d", &n);
    print_num(n);
    return 0;
}

void print_num(int count)
{
    int num;
    scanf("%d", &num);

    if(count == 0) {
        return;
    }
    printf("%d\n", num);
    print_num(count-1);
}