#include <stdio.h>

int main(void)
{
    int board[19][19];
    int n, x, y;

    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    scanf("%d", &n);
    for(int k = 0; k < n; k++) {
        scanf("%d%d", &x, &y);
        x--, y--;

        for(int i = 0; i < 19; i++) {
            board[x][i] = board[x][i] == 0 ? 1 : 0;
            board[i][y] = board[i][y] == 0 ? 1 : 0;
        }
    }

    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            if(j < 18) {
                printf("%d ", board[i][j]);
            }
            else {
                printf("%d\n", board[i][j]);
            }
        }
    }

    return 0;
}