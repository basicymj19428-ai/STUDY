#include <stdio.h>

int main(void)
{
	int a;
	int *pa = &a;
	int* pb;

	*pa = 3;
	pb = pa;

	printf("pa가 가리키고 있는 것 : %d\n", *pa);
	printf("pb가 가리키고 있는 것 : %d\n", *pb);

	return 0;
}