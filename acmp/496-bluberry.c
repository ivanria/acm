#include <stdio.h>
#include <stdlib.h>

typedef struct memb list_t;
struct memb {
	list_t *next;
	int val;
};

int main(void)
{
	FILE *ifp, *ofp;
	int N, i, sum, p_sum;
	list_t *h;
	list_t *f;
	ofp = fopen("OUTPUT.TXT", "w");
	ifp = fopen("INPUT.TXT", "r");
	fscanf(ifp, "%d", &N);
	h = (list_t *)malloc(sizeof(list_t));
	fscanf(ifp, "%d", &h->val);
	f = h;
	for (i = 0; i < N - 1; i++) {
		h->next = (list_t *)malloc(sizeof(list_t));
		h = h->next;
		fscanf(ifp, "%d", &h->val);
	}
	h->next = f;

	h = f;
	for (i = 0, sum = 0, p_sum = 0; i < N; i++) {
		sum = h->val + h->next->val + h->next->next->val;
		if (sum > p_sum)
			p_sum = sum;
		h = h->next;

	}
	fprintf(ofp, "%d\n", p_sum);
	
	fclose(ifp);
	fclose(ofp);
	return 0;
}
