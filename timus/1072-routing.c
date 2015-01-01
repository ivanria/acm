#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>

/*defines*/
#define MAX_NIC 5

#define SUCC 1
#define ERR 0

#define INT_BIT (CHAR_BIT * sizeof(int))
#define MAX(x,y) ((x) > (y)?(x):(y))
#define MIN(x,y) ((x) < (y)?(x):(y))

#define ST_SIZE 3000

#define WHITE 0
#define GREY 1
#define BLACK 2
#define INFTY INT_MAX
#define NPARENT -1
#define GRAPH 1
#define OGRAPH 0

typedef uint32_t bitmap_t;

typedef struct {
	int val[ST_SIZE];
	int head;
} stack_t;

typedef struct {
	int V; /*vertex*/
	int *p; /*parent*/
	char *c; /*color*/
	int *d; /*distance*/
	bitmap_t *adj; /*adjacency matrix*/
} graph_t;

typedef struct {
	unsigned int ip;
	unsigned int mask;
} nic_t;

typedef struct {
	int nnic;
	nic_t nic[MAX_NIC];
} host_t;


/*function declarations*/
bitmap_t *initadj(graph_t *);
bool chkadj(graph_t *, int, int);
void setadj(graph_t *, int, int);
void deladj(graph_t *, int, int);

graph_t *initgraph(int);
void bfs(graph_t *, int);
void print_path( graph_t *, int, int);

int push(stack_t *, int);
int pop(stack_t *, int *);
int enqueue(int);
int dequeue(int *);

unsigned int str2ip(char *);

int main(void)
{
	int i, j, c, m, n, k;
	char ip[16];
	char mask[16];
	host_t *hosts;
	graph_t *gr;
	scanf("%d", &n);
	hosts = malloc(sizeof(host_t) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &k);
		hosts[i].nnic = k;
		for (j = 0; j < k; j++) {
			scanf("%s", ip);
			scanf("%s", mask);
			hosts[i].nic[j].ip = str2ip(ip);
			hosts[i].nic[j].mask = str2ip(mask);
		}
	}
	gr = initgraph(n);
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (c = 0; c < hosts[i].nnic; c++) {
				for (m = 0; m < hosts[j].nnic; m++) {
					if ((hosts[i].nic[c].ip & hosts[i].nic[c].mask) ==
							(hosts[j].nic[m].ip & hosts[j].nic[m].mask)) {
						setadj(gr, i, j);
					}
				}
			}
		}
	}

	/*
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%2d", (chkadj(gr, i, j)?1:0));
		}
		printf("\n");
	}
	*/

	int sp, ep;
	scanf("%d%d", &sp, &ep);
	--sp; --ep;
	bfs(gr, ep);
	if (gr->c[sp] == WHITE) {
		printf("No\n");
		exit(0);
	}
	printf("Yes\n");
	print_path(gr, sp, ep);
	printf("\n");
	return 0;
}

void bfs(graph_t *gr, int sv)
{
	if (gr->V == 0)
		return;
	int i, u, v;
	for (i = 0; i < gr->V; i++) {
		gr->c[i] = WHITE;
		gr->d[i] = INFTY;
		gr->p[i] = NPARENT;
	}
	enqueue(sv);
	gr->d[sv] = 0;
	gr->c[sv] = GREY;
	for (; dequeue(&u);) {
		for (i = gr->V - 1; i >= 0; i--) {
			if (chkadj(gr, u, i)) {
				v = i;
				if (gr->c[v] == WHITE) {
					gr->p[v] = u;
					gr->d[v] = gr->d[u] + 1;
					gr->c[v] = GREY;
					enqueue(v);
				}
			}
		}
	}
}
void print_path(graph_t *gr, int sv, int ev)
{
	printf("%d ", sv + 1);
	if (sv == ev) {
		return;
	} else {
		print_path(gr, gr->p[sv], ev);
	}
}
graph_t *initgraph(int V)
{
	graph_t *gr;
	if ((gr = malloc(sizeof(graph_t))) == NULL)
		return NULL;
	gr->V = V;
	gr->adj = initadj(gr);
	gr->p = malloc(sizeof(int) * V);
	gr->c = malloc(sizeof(int) * V);
	gr->d = malloc(sizeof(int) * V);
	if (!gr->adj || !gr->p || !gr->c || !gr->d)
		return NULL;
	return gr;
}

stack_t st_in;
stack_t st_out;

int push(stack_t *st, int val)
{
	if (st->head == ST_SIZE) {
		return ERR; /*stack full*/
	}
	st->val[st->head] = val;
	st->head++;
	return SUCC;
}
int pop(stack_t *st, int *val)
{
	if (st->head == 0) {
		return ERR;
	} else {
		st->head--;
		*val = st->val[st->head];
		return SUCC;
	}
}
int enqueue(int val)
{
	if (push(&st_in, val) == ERR) {
		return ERR;
	} else {
		return SUCC;
	}
}
int dequeue(int *val)
{
	int tmp;
	if (pop(&st_out, &tmp) == ERR) { /*empty st_out*/
		if (pop(&st_in, &tmp) == ERR) { /*empty st_in*/
			return ERR;
		} else {
			push(&st_out, tmp);
		}
		for (;;) {
			if (pop(&st_in, &tmp) == ERR) {
				break;
			} else {
				push(&st_out, tmp);
			}
		}
		pop(&st_out, val);
		return SUCC;
	} else {
		*val = tmp;
		return SUCC;
	}
}
bitmap_t *initadj(graph_t *gr)
{
	int len;
	int V = gr->V;
	len = V * V / 2 - V / 2;
	return calloc(sizeof(bitmap_t), len / INT_BIT + 1);
}
bool chkadj(graph_t *gr, int row, int col)
{
	int n = gr->V, tmp1, tmp2;
	tmp1 = row, tmp2 = col;
	row = MAX(tmp1, tmp2);
	col = MIN(tmp1, tmp2);
	return gr->adj[(row * n + col) / INT_BIT]
		& (1 << (row * n + col) % INT_BIT);
}
void setadj(graph_t *gr, int row, int col)
{
	int n = gr->V, tmp1, tmp2;
	tmp1 = row, tmp2 = col;
	row = MAX(tmp1, tmp2);
	col = MIN(tmp1, tmp2);
	gr->adj[(row * n + col) / INT_BIT] =
		gr->adj[(row * n + col) / INT_BIT]
		| (1 << (row * n + col) % INT_BIT);
}
void deladj(graph_t *gr, int row, int col)
{
	int n = gr->V, tmp1, tmp2;
	tmp1 = row, tmp2 = col;
	row = MAX(tmp1, tmp2);
	col = MIN(tmp1, tmp2);
	gr->adj[(row * n + col) / INT_BIT] =
		gr->adj[(row * n + col) / INT_BIT]
		& ~(1 << (row * n + col) % INT_BIT);
}
unsigned int str2ip(char *str)
{
	unsigned int r, b;
	for (r = 0, b = 0; *str != '\0'; str++) {
		if (*str == '.') {
			str++;
			r = r << 8;
			r += b;
			b = 0;
		}
		b = b * 10 + (*str - '0');
	}
	r = r << 8;
	r += b;
	return r;
}
