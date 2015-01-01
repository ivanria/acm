#include <stdio.h>
#include <stdlib.h>

int func(int n, int i)
{
	int r;
	for (r = 0; n > 0; n /= 10)
		if (n % 10 == i)
			r++;
	return r;
}

int c0(int n)
{
	int r;
	for (r = 0; n > 0; n /= 10)
		if (n % 10 == 0)
			r++;
	return r;
}
int c1(int n)
{
	int r;
	for (r = 0; n > 0; n /= 10)
		if (n % 10 == 1)
			r++;
	return r;
}
int c2(int n)
{
	int r;
	for (r = 0; n > 0; n /= 10)
		if (n % 10 == 2)
			r++;
	return r;
}
int c3(int n)
{
	int r;
	for (r = 0; n > 0; n /= 10)
		if (n % 10 == 3)
			r++;
	return r;
}
int c4(int n)
{
	int r;
	for (r = 0; n > 0; n /= 10)
		if (n % 10 == 4)
			r++;
	return r;
}
int c5(int n)
{
	int r;
	for (r = 0; n > 0; n /= 10)
		if (n % 10 == 5)
			r++;
	return r;
}
int c6(int n)
{
	int r;
	for (r = 0; n > 0; n /= 10)
		if (n % 10 == 6)
			r++;
	return r;
}
int c7(int n)
{
	int r;
	for (r = 0; n > 0; n /= 10)
		if (n % 10 == 7)
			r++;
	return r;
}
int c8(int n)
{
	int r;
	for (r = 0; n > 0; n /= 10)
		if (n % 10 == 8)
			r++;
	return r;
}
int c9(int n)
{
	int r;
	for (r = 0; n > 0; n /= 10)
		if (n % 10 == 9)
			r++;
	return r;
}

int (*funcarr[10])(int) = {c0,c1,c2,c3,c4,c5,c6,c7,c8,c9};

int main(int argc, char *argv[])
{
	FILE *ifp, *ofp;
	int N, M, i, j, c, r;
	ifp = fopen("INPUT.TXT", "r");
	ofp = fopen("OUTPUT.TXT", "w");
	fscanf(ifp, "%d %d", &N, &M);


	for (c = 0, r = 0; c < 10; c++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= M; j++) {
				r += func(i * j, c);
			}
		}
		fprintf(ofp, "%d\n", r);
		r = 0;
	}
	
	fclose(ifp);
	fclose(ofp);
	return 0;
}
