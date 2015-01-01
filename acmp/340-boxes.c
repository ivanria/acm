#include <stdio.h>

#define a edge[0]
#define b edge[1]
#define c edge[2]

struct box {
	int edge[3];
};

void sort(int *arr)
{
        int tmp;
        if (arr[0] > arr[1]) {
                tmp = arr[0]; arr[0] = arr[1]; arr[1] = tmp;
	}
        if (arr[0] > arr[2]) {
                tmp = arr[0]; arr[0] = arr[2]; arr[2] = tmp;
	}
        if (arr[1] > arr[2]) {
                tmp = arr[1]; arr[1] = arr[2]; arr[2] = tmp;
	}
}


int main(void)
{
	FILE *ifp, *ofp;

	struct box B1;
	struct box B2;

	ofp = fopen("OUTPUT.TXT", "w");
	ifp = fopen("INPUT.TXT", "r");
	fscanf(ifp, "%d %d %d %d %d %d",
			&B1.a, &B1.b, &B1.c, &B2.a, &B2.b, &B2.c);

	sort(&B1.a);
	sort(&B2.a);

	if (B1.a == B2.a && B1.b == B2.b && B1.c == B2.c) {
		fprintf(ofp, "Boxes are equal\n");
		goto end;
	}
	if (B1.a >= B2.a && B1.b >= B2.b && B1.c >= B2.c) {
		fprintf(ofp, "The first box is larger than the second one\n");
		goto end;
	}
	if (B1.a <= B2.a && B1.b <= B2.b && B1.c <= B2.c) {
		fprintf(ofp, "The first box is smaller than the second one\n");
		goto end;
	}
	fprintf(ofp, "Boxes are incomparable\n");
end:
	fclose(ifp);
	fclose(ofp);
	return 0;
}
