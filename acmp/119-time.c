#include <stdio.h>

#define MAX 86400

struct memb {
	int sign;
	char h; char m; char s;
};

struct memb moment[MAX];

int main(void)
{
	FILE *ifp, *ofp;
	int N, val, i, j, h, m, s;
	char tmp[10];

	ofp = fopen("OUTPUT.TXT", "w");
	ifp = fopen("INPUT.TXT", "r");
	fscanf(ifp, "%d", &N);
	for (i = 0; i < N; i++) {
		fscanf(ifp, "%s", tmp);
		//printf("%s ", tmp);
		for (j = 0, h = 0; tmp[j] != '\0'; j++)
			h = h * 10 + (tmp[j] - '0');
		fscanf(ifp, "%s", tmp);
		//printf("%s ", tmp);
		for (j = 0, m = 0; tmp[j] != '\0'; j++)
			m = m * 10 + (tmp[j] - '0');
		fscanf(ifp, "%s", tmp);
		//printf("%s\n", tmp);
		for (j = 0, s = 0; tmp[j] != '\0'; j++)
			s = s * 10 + (tmp[j] - '0');
		val = ;
		moment[val].sign = 1234;
		moment[val].h = h; moment[val].m = m; moment[val].s = s;
	}
	for (i = 0; i < MAX; i++) {
		if (moment[i].sign == 1234) {
			fprintf(ofp, "%d %d %d\n",
					moment[i].h, moment[i].m,
					moment[i].s);
		}
	}
	
	fclose(ifp);
	fclose(ofp);
	return 0;
}
