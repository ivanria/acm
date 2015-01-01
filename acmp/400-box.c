#include <stdio.h>


int main(void)
{
	FILE *ifp, *ofp;
	int A, B, C;
	ofp = fopen("OUTPUT.TXT", "w");
	ifp = fopen("INPUT.TXT", "r");
	fscanf(ifp, "%d %d %d", &A, &B, &C);
	
	
	fclose(ifp);
	fclose(ofp);
	return 0;
}
