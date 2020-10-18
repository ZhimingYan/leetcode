typedef struct myhash {
    int key; //key为char类型，加入hash前需要强转为int才能加入hash中，否则存在问题
    int val;
    UT_hash_handle hh; //
}hash;

hash *g_hash = NULL; //

void addHash(char a)
{
    hash *s;
    int key = (int)a; //必不可少

    HASH_FIND_INT(g_hash, &key, s);
    if (s) {
        printf("%d\n", s->val);
    } else {
        s = (hash *)malloc(sizeof(hash));
        s->key = a;
        s->val = 1;
        HASH_ADD_INT(g_hash, key, s);
    }
}

void updateHash(char a, int newval)
{
    hash *s;
    int key = (int)a;//必不可少

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

void delOneKey(char a)
{
    hash *s;
    int key = (int)a;//必不可少

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
        printf("key(%c)  val(%d)   ", s->key, s->val);
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
    addHash('c');
    addHash('f');
    addHash('a');
    addHash('s');
    addHash('f');
    iterHash();

    updateHash('s', 100);
    iterHash();
    delHash();
    iterHash();

    addHash('c');
    addHash('f');
    addHash('a');
    iterHash();
    sortHash();
    iterHash();

    system("pause");
    return 0;
}