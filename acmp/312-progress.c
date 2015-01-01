#include <stdio.h>


int main(int argc, char *argv[])
{
	FILE *ifp, *ofp;
	int A1, A2, N, D;
	ofp = fopen("OUTPUT.TXT", "w");
	ifp = fopen("INPUT.TXT", "r");
	fscanf(ifp, "%d %d %d", &A1, &A2, &N);
	D = A2 - A1;
	fprintf(ofp, "%d\n", A1 + (N - 1) * D);
	fclose(ifp);
	fclose(ofp);
	return 0;
}
