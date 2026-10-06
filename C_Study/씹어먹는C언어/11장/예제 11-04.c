#include <stdio.h>

int slave(int master_money) 
{
	master_money += 10000;
	return master_money;
}

int main(void)
{
	int my_money = 100000;
	printf("2009.12.12 재산 : $%d\n", slave(my_money));

	return 0;
}