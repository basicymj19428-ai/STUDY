#include <stdio.h>
int indigit(char c);

int main(void)
{
	char input;

	scanf("%c", &input);

	if (indigit(input)) {
		printf("%c는 숫자입니다.\n", input);
	}
	else
	{
		printf("%c는 숫자가 아닙니다.\n", input);
	}

	return 0;
}

int indigit(char c)
{
	if (48 <= c && c <= 57) {
		return 1;
	}
	else
	{
		return 0;
	}
}