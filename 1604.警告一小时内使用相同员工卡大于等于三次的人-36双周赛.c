/*
提交版本
*/
#define MAXNAME 10
#define MAXLEN 1000

typedef struct tagHash {
	char name[MAXNAME];
	int time[MAXLEN];
	int size;
	UT_hash_handle hh;
} Hash;

Hash* g_hash;

void AddHash(const char* name, int time) {
	Hash *p;
	HASH_FIND_STR(g_hash, name, p);
	if (p == NULL) {
		p = (Hash *)malloc(sizeof(Hash));
		strcpy(p->name, name);
		p->time[0] = time;
		p->size = 1;
		HASH_ADD_STR(g_hash, name, p);
	}
	else {
		p->time[p->size] = time;
		p->size++;
	}
}

void FreeHash() {
	Hash *s, *tmp;
	HASH_ITER(hh, g_hash, s, tmp) {
		HASH_DEL(g_hash, s);
		free(s);
	}
}

int cmp(Hash *a, Hash *b)
{
	return strcmp(a->name, b->name); //从小到大
}

void sortHash()
{
	HASH_SORT(g_hash, cmp);
}

int TimeTransf(const char *time) {
	if (strlen(time) != 5) {
		return 0;
	}
	int hour = (time[0] - '0') * 10 + time[1] - '0';
	int min = (time[3] - '0') * 10 + time[4] - '0';
	return hour * 60 + min;
}

int cmpInt(const void *a, const void *b) {
	int *x = (int *)a;
	int *y = (int *)b;
	return *x - *y;
}

char ** alertNames(char ** keyName, int keyNameSize, char ** keyTime, int keyTimeSize, int* returnSize){
	g_hash = NULL;
	for (int i = 0; i < keyNameSize; i++) {
		int time = TimeTransf(keyTime[i]);
		AddHash(keyName[i], time);
	}

	sortHash();	
	char **res = (char**)malloc(sizeof(char *) * MAXLEN);


	Hash *s, *tmp;
	int index = 0;
	HASH_ITER(hh, g_hash, s, tmp) {
		if (s->size < 3) {
			continue;
		}

		qsort(s->time, s->size, sizeof(int), cmpInt);
		for (int i = 2; i < s->size; i++) {
			if (s->time[i] - s->time[i - 2] <= 60) {
				res[index] = (char *)malloc(sizeof(char) * MAXNAME);
				strcpy(res[index], s->name);
				index++;
				break;
			}
		}
	}
    *returnSize = index;
	return res;
}

/*
调试版本
*/

#include "uthash.h"
#include <stdio.h>

#define MAXNAME 10
#define MAXLEN 100000

typedef struct tagHash {
	char name[MAXNAME];
	int time[MAXLEN];
	int size;
	UT_hash_handle hh;
} Hash;

Hash* g_hash;

void AddHash(const char* name, int time) {
	Hash *p;
	HASH_FIND_STR(g_hash, name, p);
	if (p == NULL) {
		p = (Hash *)malloc(sizeof(Hash));
		strcpy(p->name, name);
		p->time[0] = time;
		p->size = 1;
		HASH_ADD_STR(g_hash, name, p);
	}
	else {
		p->time[p->size] = time;
		p->size++;
	}
}

void FreeHash() {
	Hash *s, *tmp;
	HASH_ITER(hh, g_hash, s, tmp) {
		HASH_DEL(g_hash, s);
		free(s);
	}
}

int cmp(Hash *a, Hash *b)
{
	return strcmp(a->name, b->name); //从小到大
}

void sortHash()
{
	HASH_SORT(g_hash, cmp);
}

int TimeTransf(const char *time) {
	if (strlen(time) != 5) {
		return 0;
	}
	int hour = (time[0] - '0') * 10 + time[1] - '0';
	int min = (time[3] - '0') * 10 + time[4] - '0';
	return hour * 60 + min;
}

int cmpInt(const void *a, const void *b) {
	int *x = (int *)a;
	int *y = (int *)b;
	return *x - *y;
}

char ** alertNames(char ** keyName, int keyNameSize, char ** keyTime, int keyTimeSize, int* returnSize){
	g_hash = NULL;
	for (int i = 0; i < keyNameSize; i++) {
		int time = TimeTransf(keyTime[i]);
		AddHash(keyName[i], time);
	}

	sortHash();


	//char res[MAXNAME][MAXLEN] = { 0 };

	
	char **res = (char**)malloc(sizeof(char *) * MAXLEN);


	Hash *s, *tmp;
	int index = 0;
	HASH_ITER(hh, g_hash, s, tmp) {
		if (s->size < 3) {
			continue;
		}

		qsort(s->time, s->size, sizeof(int), cmpInt);
		for (int i = 0; i < s->size; i++) {
			printf("%d\t", s->time[i]);
		}
		printf("\n");
		if (24 * 60 - s->time[s->size - 1] + s->time[0] >= 60) {
			res[index] = (char *)malloc(sizeof(char) * MAXNAME);
			strcpy(res[index], s->name);
			index++;
		}
		for (int i = 2; i < s->size; i++) {
			if (s->time[i] - s->time[i - 2] <= 60) {
				res[index] = (char *)malloc(sizeof(char) * MAXNAME);
				strcpy(res[index], s->name);
				index++;
				break;
			}
		}
	}

	printf("%s\n", res[0]);

	// *returnSize = index;

//	 printf("%d\n", *returnSize);
	return res;
}


int main() {
	char *a[] = { "daniel", "daniel", "daniel", "luis", "luis", "luis", "luis" };
	char *b[] = { "10:00", "10:40", "11:00", "09:00", "11:00", "13:00", "15:00" };
	for (int i = 0; i < 7; i++) {
		printf("%s\n", a[i]);
	}
	char **c = NULL;
	int *returnSize = NULL;
	c = alertNames(a, 7, b, 7, returnSize);
	
	for (int i = 0; i < 1; i++) {
		printf("%s\n", c[i]);
	}
	//printf("%d\n", *returnSize);
	return 0;


}