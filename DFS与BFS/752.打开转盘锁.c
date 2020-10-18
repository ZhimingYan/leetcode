/*
 * @lc app=leetcode.cn id=752 lang=c
 *
 * [752] 打开转盘锁
 */

// @lc code=start
//暂时未解决

#define MAXLEN 100000
#define STRLEN 5

char g_quene[MAXLEN][STRLEN];
int g_head;
int g_tail;

typedef struct tagHash {
	char key[STRLEN];
	int val;
	UT_hash_handle hh;
} Hash;

Hash * g_hash1;
Hash * g_hash2;
char g_quene[MAXLEN][STRLEN];
int g_head;
int g_tail;



void AddHash(char *s, Hash *hash)
{
	Hash *p = NULL;
	HASH_FIND_STR(hash, s, p);
	if (p == NULL) {
		p = (Hash *)malloc(sizeof(Hash));
		strcpy(p->key, s);
		p->val = 1;
		HASH_ADD_STR(hash, key, p);
	} else {
		p->val++;
	}
}

int FindHash(const char *s, Hash *hash)
{
	Hash *p = NULL;
	HASH_FIND_STR(hash, s, p);
	if (p == NULL) {
		return 0;
	}
	return p->val;
}

void FreeHash(Hash *hash)
{
	Hash *cur = NULL;
	Hash *tmp = NULL;
	HASH_ITER(hh, hash, cur, tmp) {
		HASH_DEL(hash, cur);
		free(cur);
	}
}


void PlusOne(char *s, int i)
{
	if (s[i] == '9') {
		s[i] = '0';
	} else {
		s[i]++;
	}
}

void SubOne(char *s, int i)
{
	if (s[i] == '0') {
		s[i] = '9';
	} else {
		s[i]--;
	}
}


int openLock(char ** deadends, int deadendsSize, char * target){
	memset(g_quene, 0, sizeof(g_quene));
	g_head = 0;
	g_tail = 0;
	g_hash1 = NULL;
	g_hash2 = NULL;

	for (int i = 0; i < deadendsSize; i++) {
		AddHash(deadends[i], g_hash1);
	}

	strcpy(g_quene[g_tail++], "0000");
    //printf("%d  %d\n", g_head, g_tail);
	int step = 0;
	while (g_tail > g_head) {
		int size = g_tail - g_head;

        printf("%d %d %d\n",step, size, __LINE__);
        printf("%d  %d\n", g_head, g_tail);
		for (int i = 0; i < size; i++) {
            
			char tmp[STRLEN];
            printf("%s\n", g_quene[g_head]);
            strcpy(tmp, g_quene[g_head++]); 
            printf("%s\n",tmp);
			if (FindHash(tmp, g_hash1)){
				continue;
			}
			if (strcmp(tmp, target) == 0) {
				return step;
			}
			AddHash(tmp, g_hash2);
			for (int j = 0; j < 4; j++) {
                char swap1[STRLEN];
                char swap2[STRLEN];
                strcpy(swap1, tmp);
                strcpy(swap2, tmp);
                PlusOne(swap1, j);
				if (FindHash(swap1, g_hash2) == 0) {
					strcpy(g_quene[g_tail++], swap1);
                    AddHash(swap1, g_hash2);
                    printf("%s   %d\n",swap1,__LINE__);
				}
                SubOne(swap2, j);
				if (FindHash(swap2, g_hash2) == 0) {  
					strcpy(g_quene[g_tail++], swap2);
                    AddHash(swap2, g_hash2);
                    printf("%s   %d\n",swap2,__LINE__);
				}
			}
		}
		step++;
	}

	FreeHash(g_hash2);
	FreeHash(g_hash1);
	return step;
}
// @lc code=end

