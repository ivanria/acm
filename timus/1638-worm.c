#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int w1;
	int w2;
	int first;
	int last;
	int result;
	scanf("%d", &w1); scanf("%d", &w2);
	scanf("%d", &first); scanf("%d", &last);
	if (first < last) {
		result = (last - first - 1) * w1 + ((last - first) * 2 * w2) ;
		goto exit;
	}
	if (first == last) {
		result = w1;
		goto exit;
	}
	if (first > last) {
		result = (first - last + 1) * w1 + ((first - last) * 2 * w2);
		goto exit;
	}
exit:
	printf("%d\n", result);
	return 0;
}
