#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
 
#define False 0
#define True 1
#define STRL 31
//#define HASH_MAX 65536
#define HASH_STORE 10
#define PRIME_GEN 10000


int str_to_int(char *str)
{
        int result;
        char sign;
        if (*str == '-') {
                sign = '-';
                str++;
        } else if (*str >= '0' && *str <= '9') {
                sign = '+';
        }
        for (result = 0; *str != '\0' && *str != '\n'; str++) {
                if ((*str < '0') || (*str > '9'))
                        return 0;
                result = result * 10 + (*str - '0');
        }
        if (sign == '-')
                result = ~result + 1;
        return result;
}

void read_str(register char *str)
{
        for (; ; str++) {
                read(0, str, 1);
                if (*str == '\n') {
                        *str = '\0';
                        break;
                }
        }
}

int prime(int n)
{
        int i;
        for (i = 2; i * i < n; i++) {
                if (n % i == 0)
                        break;
        }               
        if (i * i <= n)
                return False;
        else
                return True;
        return 0;
}

int hash_ease(char *str, int t_size)
{
	int h, a = 127;
	for (; *str != '\0'; str++)
		h = (a * h + *str) % t_size;
	return h;
}


struct member {
	unsigned short hash;
	char realloc;
	short str_count;
	char **str;
};
 
#define STR_PER_HASH 100

int add_member(register struct member *table, register char *str, unsigned short hash)
{
	int i, c;
	char repeat_flag = False;
	if (table->hash != hash) {
		//printf("-------------------\n new member\n----------------\nhash: %d name: %s\n", hash, str);
		table->hash = hash;
		table->realloc = 1;
		table->str = (char **)malloc(sizeof(char **) * STR_PER_HASH);
		table->str[0] = (char *)malloc(sizeof(char) * STRL);
		strcpy(table->str[0], str);
		table->str_count = 1;
		//printf("name in memory: %s\n-------------------\n", table->str[0]);
	} else {
		for (i = 0, c = table->str_count; i < c; i++) {
			if (strcmp(table->str[i], str) == 0) {
				//printf("\nhash:%d repeat on name:%s  --  ", hash, str);
				repeat_flag = True;
				return 1;
			}
		}
		if (repeat_flag == False) { //collision
			//printf("\ncollision in hash %d name: %s\n", hash, str);
			if (table->str_count >= STR_PER_HASH * table->realloc) {
				printf("\nrealloc. Old: %d, new: %d\n", table->realloc * STR_PER_HASH, (table->realloc + 1) * STR_PER_HASH);
				table->realloc++;
				table->str = (char **)realloc(table->str, sizeof(char **) * STR_PER_HASH * table->realloc);
			}
			table->str[table->str_count] = (char *)malloc(sizeof(char) * STRL);
			strcpy(table->str[table->str_count], str);
			table->str_count++;
			//for (i = 0; i < table->str_count; i++) {
				//printf("%s, ", table->str[i]);
			//}
			//printf("\n");
		}
	}
	return 0;
}


int main(int argc, char *argv[])
{
        int N, i, ht_size;
	register int c;
        register unsigned short hash;
	struct member *htable;
        char name[STRL];
	read_str(name);
	N = str_to_int(name);

	ht_size = N * HASH_STORE;
	for (i = 1; i < PRIME_GEN; i++) {
		if (prime(ht_size + i) == True) {
			ht_size = ht_size + i;
			//printf("ht size: %d\n", ht_size);
			htable = (struct member *)calloc(ht_size, sizeof(struct member));
			break;
		}
	}

	//htable = (struct member *)malloc(sizeof(struct member) * HASH_MAX);
        if (htable == NULL) {
                printf("need memory\n");
                return 0;
        }
 
        for (i = 0, c = 0; i < N; i++) {
                read_str(name);
                hash = hash_ease(name, ht_size);
		c += add_member(htable + hash, name, hash);
        }
        printf("%d\n", c);
        return 0;
}

        //unsigned char *htable = (unsigned char *)malloc(sizeof(unsigned char) * HASH_MAX);
