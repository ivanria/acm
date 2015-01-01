#include <stdio.h>


int main(void)
{
	FILE *ifp, *ofp;
	unsigned long int N, res;
	ofp = fopen("OUTPUT.TXT", "w");
	ifp = fopen("INPUT.TXT", "r");
	fscanf(ifp, "%lu", &N);
	res = N;
	for (; N > 0; N /= 2) {
		res += N % 2;
	}
	fprintf(ofp, "%lu\n", res);
	
	fclose(ifp);
	fclose(ofp);
	return 0;
}
