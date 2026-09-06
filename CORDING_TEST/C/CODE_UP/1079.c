#include <stdio.h>

int main(void)
{
    char word;

    while(word != 'q') {
        scanf("%c ", &word);

        if(word != 'q') {
            printf("%c\n", word);
        }
        else {
            printf("%c\n", 'q');
            break;
        }
    }

    return 0;
}