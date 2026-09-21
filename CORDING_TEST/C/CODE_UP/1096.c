#include <stdio.h>

int main(void)
{
    int n, x, y;
    int count[20][20] = {0};

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        count[x-1][y-1] = 1;
    }

    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            if(j < 18) {
                printf("%d ", count[i][j]);
            }
            else {
                printf("%d\n", count[i][j]);
            }
        }
    }

    return 0;
}