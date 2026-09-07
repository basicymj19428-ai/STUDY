#include <stdio.h>

int main(void)
{
	int guess = 5;
	int prime[1000];

	int index = 1;
	int i, ok;

	prime[0] = 2;
	prime[1] = 3;

	for (;;) {
		ok = 0;
		for (i = 0; i <= index; i++) {
			if (guess % prime[i] != 0) {
				ok++;
			}
			else {
				break;
			}
		}

		if (ok == (index + 1)) {
			index++;
			prime[index] = guess;
			printf("소수 : %d\n", prime[index]);

			if (index == 999) {
				break;
			}
		}
		guess += 2;
	}

	return 0;
}