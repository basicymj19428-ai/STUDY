#include <stdlib.h>  //system 문장을 위해 삽입

int main(void)
{
    system("dir");  //파일과 디렉터리 정보가 출력
    system("pause");  //pause 명령 실행
    system("cls");  //콘솔창에 출력된 내용이 전부 지워짐

    return 0;
}