#include <stdio.h>

int main(void) {
	char input;

	printf("(소문자) 알파벳 읽기\n");
	printf("(알파벳) : ");
	scanf("%c", &input);

	switch (input) {
	case 'a':
		printf("에이\n");
		break;

	case 'b':
		printf("비\n");
		break;

	case 'c':
		printf("씨\n");
		break;

	default:
		printf("읽을수 없습니다.\n");
		break;
	}

	return 0;
}