#include <stdio.h>

int slave(int my_money)
{
	my_money += 10000;
	return my_money;
}

int main()
{
	int my_money = 100000;
	printf("2009.12.12 재산 : $%d\n", slave(my_money));
	printf("my_money : %d", my_money);

	return 0;
}