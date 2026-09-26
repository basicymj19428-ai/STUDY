#include <stdio.h>

int main(void)
{
    int board[100][100] = {0};
    int h, w;
    int n;
    int l, d, x, y;

    scanf("%d%d", &h, &w);
    // board[h][w];

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &l, &d, &x, &y);
        x--, y--;

        if(d == 0) {
            for(int j = y; j < y + l; j++) {
                board[x][j] = 1;
            }
        }
        else {
            for(int k = x; k < x + l; k++) {
                board[k][y] = 1;
            }
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(j < w - 1) {
                printf("%d ", board[i][j]);
            }
            else {
                printf("%d\n", board[i][j]);
            }
        }
    }

    return 0;
}