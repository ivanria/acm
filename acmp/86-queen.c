#include <stdio.h>
void main(void)
{
	FILE *ip, *op;
	int N;
	op = fopen("OUTPUT.TXT", "w");
	ip = fopen("INPUT.TXT", "r");
	fscanf(ip, "%d", &N);
	fprintf(op, "%d", N * N - 3 * N + 2);
}
