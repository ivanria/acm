#include <stdio.h>

int main(void)
{
	FILE *ifp, *ofp;
	int N;
	ofp = fopen("OUTPUT.TXT", "w");
	ifp = fopen("INPUT.TXT", "r");
	fscanf(ifp, "%d", &N);
	if (N < 0) {
		goto neg;
	}
	if (N == 0) {
		fprintf(ofp, "%d\n", 1);
		goto end;
	}
	if (N % 2 != 0) {
		fprintf(ofp, "%d\n", N * (N / 2) + N);
		goto end;
	}
	if (N % 2 == 0) {
		fprintf(ofp, "%d\n", N * (N / 2) + (N / 2));
		goto end;
	}
neg:
	if (N % 2 != 0) {
		fprintf(ofp, "%d\n", -(N * (N / 2) - N - 1));

		goto end;
	}
	if (N % 2 == 0) {
		fprintf(ofp, "%d\n", -(N * (N / 2) - (N / 2) - 1));
		goto end;
	}

end:
	fclose(ifp);
	fclose(ofp);
	return 0;
}
