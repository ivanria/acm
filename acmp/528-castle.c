#include <stdio.h>


int main(void)
{
	FILE *ifp, *ofp;
	int K, N, Xk, i, r;
	ofp = fopen("OUTPUT.TXT", "w");
	ifp = fopen("INPUT.TXT", "r");
	fscanf(ifp, "%d %d", &N, &K);
	Xk = (2 * K - (K - 1));

	fclose(ifp);
	fclose(ofp);
	return 0;
}
