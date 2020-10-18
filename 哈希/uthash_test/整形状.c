typedef struct myhash {
    int key;
    int val;
    UT_hash_handle hh; //
}hash;

hash *g_hash = NULL; //

void addHash(int a)
{
    hash *s;

    HASH_FIND_INT(g_hash, &a, s);
    if (s) {
        printf("%d\n", s->val);
    } else {
        s = (hash *)malloc(sizeof(hash));
        s->key = a;
        s->val = 1;
        HASH_ADD_INT(g_hash, key, s);
    }
}

void updateHash(int key, int newval)
{
    hash *s;

    HASH_FIND_INT(g_hash, &key, s);
    if (s) {
        printf("%d\n", s->val);
        s->val = newval;
    } else {
        s = (hash *)malloc(sizeof(hash));
        s->key = key;
        s->val = newval;
        HASH_ADD_INT(g_hash, key, s);
    }    
}

void delOneKey(int key)
{
    hash *s;

    HASH_FIND_INT(g_hash, &key, s);

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
        printf("key(%d)  val(%d)   ", s->key, s->val);
    } 
    printf("\n**************\n");
}

int cmp(hash *a, hash *b)
{
    return (a->key - b->key); //从小到大
}

void sortHash()
{
    HASH_SORT(g_hash, cmp);
}

int main()
{
    addHash(1);
    addHash(5);
    addHash(3);
    addHash(4);
    addHash(7);
    iterHash();

    updateHash(5, 100);
    iterHash();
    delHash();
    iterHash();

    addHash(1);
    addHash(5);
    addHash(3);
    iterHash();
    sortHash();
    iterHash();

    system("pause");
    return 0;
}