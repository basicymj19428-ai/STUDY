#include <stdio.h>

int main(void)
{
    int x = 1, y = 1;
    int board[10][10];

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    while(1) {
        if(board[x][y] == 0) {
            board[x][y] = 9;
            y++;
        }
        if(board[x][y] == 1) {
            y--;
            x++;
        }
        if(board[x][y] == 2) {
            board[x][y] = 9;
            break;
        }
        else if(board[x][y + 1] == 1 && board[x + 1][y] == 1) {
            if(board[x][y] == 0) {
                board[x][y] = 9;
            }

            break;
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(j < 9) {
                printf("%d ", board[i][j]);
            }
            else {
                printf("%d\n", board[i][j]);
            }
        }
    }

    return 0;
}