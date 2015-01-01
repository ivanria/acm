#include <stdio.h>


int main(void)
{
	FILE *ifp, *ofp;
	int N, M, quot, i;
	int dif1, dif2;
	ofp = fopen("OUTPUT.TXT", "w");
	ifp = fopen("INPUT.TXT", "r");
	fscanf(ifp, "%d %d", &N, &M);
	quot = N / M;
	if (quot * M == N) {
		for (i = 0; i < M; i++)
			fprintf(ofp, "%d ", quot);
	} else {
		dif1 = N - quot * M;
		dif2 = N - (quot + 1) * M;
		if (dif2 < 0)
			dif2 = -dif2;
		if (dif1 < dif2) {
			for (i = 0; i < M - dif1; i++)
				fprintf(ofp, "%d ", quot);
			for (i = 0; i < dif1; i++)
				fprintf(ofp, "%d ", quot + 1);
		} else {
			for (i = 0; i < dif2; i++)
				fprintf(ofp, "%d ", quot);
			for (i = 0; i < M - dif2; i++)
				fprintf(ofp, "%d ", quot + 1);
		}
	}

end:
	fprintf(ofp, "\n");
	fclose(ifp);
	fclose(ofp);
	return 0;
}
