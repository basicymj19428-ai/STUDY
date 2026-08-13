#include <stdio.h>

int main(void)
{
	int a = 1, b = 1, c = 1, d= 1;

	a = a + 1;  //a에 a에 1을 더한 값을 대입
	printf("a ; %d\n", a);

	b += 1;
	printf("b : %d\n", b);

	++c;
	printf("c : %d\n", c);

	d++;
	printf("c : %d\n", d);

	return 0;
}