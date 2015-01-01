#include <stdio.h>


int main(int argc, char *argv[])
{
	FILE *ifp, *ofp;
	int P, S, d;
	ofp = fopen("OUTPUT.TXT", "w");
	ifp = fopen("INPUT.TXT", "r");
	fscanf(ifp, "%d%d", &S, &P);
	for (d = 2; d < P - 1; d++) {
		if (P % d == 0) {
			if ((P / d) + d == S) {
				fprintf(ofp, "%d %d\n", d, P / d);
				break;
			}
		}
	}
	
	fclose(ifp);
	fclose(ofp);
	return 0;
}
