#define MAX_KEY_SIZE 100

typedef struct myhash {
    char key[MAX_KEY_SIZE];
    int val;
    UT_hash_handle hh; //
}hash;

hash *g_hash = NULL; //

void addHash(char *str)
{
    hash *s;

    HASH_FIND_STR(g_hash, str, s);
    if (s) {
        printf("%d\n", s->val);
    } else {
        s = (hash *)malloc(sizeof(hash));
        strcpy(s->key, str);
        s->val = 1;
        HASH_ADD_STR(g_hash, key, s);
    }
}

void updateHash(char *key, int newval)
{
    hash *s;

    HASH_FIND_STR(g_hash, key, s);
    if (s) {
        printf("%d\n", s->val);
        s->val = newval;
    } else {
        s = (hash *)malloc(sizeof(hash));
        strcpy(s->key, key);
        s->val = newval;
        HASH_ADD_STR(g_hash, key, s);
    }    
}

void delOneKey(char *key)
{
    hash *s;

    HASH_FIND_STR(g_hash, key, s);

    if (s) {
        HASH_DEL(g_hash, s);
        free(s);
    }    
}

void delHash()
{
    hash *s, *tmp;

    HASH_ITER(hh, g_hash, s, tmp) {
        HASH_DEL(g_hash, s);
        free(s);
    }
}

void iterHash()
{
    hash *s, *tmp;

    HASH_ITER(hh, g_hash, s, tmp) {
        printf("key(%s)  val(%d)   ", s->key, s->val);
    } 
    printf("\n**************\n");
}

int cmp(hash *a, hash *b)
{
    return strcmp(a->key, b->key); //从小到大
}

void sortHash()
{
    HASH_SORT(g_hash, cmp);
}

int main()
{
    addHash("bcd");
    addHash("acf");
    addHash("hgfs");
    addHash("qqs");
    addHash("fdgdsfg");
    iterHash();

    updateHash("acf", 100);
    iterHash();
    delHash();
    iterHash();

    addHash("bcd");
    addHash("acf");
    addHash("hgfs");
    iterHash();
    sortHash();
    iterHash();

    system("pause");
    return 0;
}