#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int T1, T2;
	int i, try;
	scanf("%d %d", &T1, &T2);
	for (i = 0; i < 10; i++) {
		scanf("%d", &try);
		T2 -= try * 20;
	}
	if (T1 - T2 > 0)
		printf("Dirty debug :(\n");
	else
		printf("No chance.\n");

	return 0;
}
