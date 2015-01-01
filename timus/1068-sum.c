#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int n, tmp;
	long sum;
	scanf("%d", &n);
	if (n > 10000 || n < -10000) {
		printf("%d\n", 0);
		return 0;
	}

	if (n == 0) {
		printf("%d\n", 1);
		return 0;
	}
	if (n > 0) { /* positive */
		if (n % 2 == 0) { /* even */
			sum = n * (n / 2 - 1) + n + (n / 2);
		} else { /* not even */
			sum = n * (n / 2) + n;
		}
	} else { /* negative */
		if (n % 2 == 0) { /* even */
			sum = n * (n / 2 + 1) - n - (n / 2) - 1;
			tmp = ~sum + 1;
			sum = tmp;
		} else { /* not even */
			sum = n * (n / 2) - n - 1;
			tmp = ~sum + 1;
			sum = tmp;
		}
	}

	printf("%ld\n", sum);
	return 0;
}

/* n * (n / 2) + n not even */
/* n * ((n / 2) - 1) + n + (n / 2) even */
/* n * (n / 2) - n - 1 negative not even */
/* n * ((n / 2) + 1) - n - (n / 2) - 1 negative even */
