struct stkey {
    int a;
    char b;
};

typedef struct myhash {
    struct stkey key;
    int val;
    UT_hash_handle hh; //
}hash;

hash *g_hash = NULL; //

void addHash(struct stkey *key)
{
    hash *s;

    HASH_FIND(hh, g_hash, key, sizeof(struct stkey), s);
    if (s) {
        printf("%d\n", s->val);
    } else {
        s = (hash *)malloc(sizeof(hash));
        s->key.a = key->a;
        s->key.b = key->b;
        s->val = 1;
        HASH_ADD(hh, g_hash, key, sizeof(struct stkey), s);
    }
}

void updateHash(struct stkey *key, int newval)
{
    hash *s;

    HASH_FIND(hh, g_hash, key, sizeof(struct stkey), s);
    if (s) {
        printf("%d\n", s->val);
        s->val = newval;
    } else {
        s = (hash *)malloc(sizeof(hash));
        s->key.a = key->a;
        s->key.b = key->b;
        s->val = newval;
        HASH_ADD(hh, g_hash, key, sizeof(struct stkey), s);
    }    
}

void delOneKey(struct stkey *key)
{
    hash *s;

    HASH_FIND(hh, g_hash, key, sizeof(struct stkey), s);

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
        printf("key.a(%d) key.b(%c)  val(%d)   ", s->key.a, s->key.b, s->val);
    } 
    printf("\n**************\n");
}

int cmp(hash *a, hash *b)
{
    return (a->key.a - b->key.a); //从小到大
}

void sortHash()
{
    HASH_SORT(g_hash, cmp);
}

int main()
{
    struct stkey a, b, c;

    a.a = 12;
    a.b = 'c';

    b.a = 3;
    b.b = 'a';

    c.a = 5;
    c.b = 'd';

    addHash(&a);
    addHash(&b);
    addHash(&c);
    iterHash();

    updateHash(&b, 100);
    iterHash();
    delHash();
    iterHash();

    addHash(&a);
    addHash(&b);
    addHash(&c);
    iterHash();
    sortHash();
    iterHash();

    system("pause");
    return 0;
}
