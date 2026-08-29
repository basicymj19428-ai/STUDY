#include <stdio.h>

int main(void)
{
    int season;
    scanf("%d", &season);

    if(season == 12 || season == 1 || season == 2) {
        printf("winter\n");
    }
    else if(season == 3 || season == 4 || season == 5) {
        printf("spring\n");
    }
    else if(season == 6 || season == 7 || season == 8) {
        printf("summer\n");
    }
    else {
        printf("fall\n");
    }

    return 0;
}