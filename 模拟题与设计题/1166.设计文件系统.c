#define MAXLEN 100
typedef struct {
    char path[MAXLEN];
    int val;
    
} FileSystem;

typedef struct myHash {
    char key[MAXLEN];
    int val;
    UT_hash_handle hh;
} Hash;

Hash *g_hash = NULL;

bool AddHash(const char *s, int _val)
{
    int len = strlen(s);
    Hash *p = NULL;
    HASH_FIND_STR(g_hash, s, p);
    if (p == NULL) {
        p = (Hash *)malloc(sizeof(Hash));
        if (p == NULL) {
            return;
        }
        strncpy(p->key, s, len);
        p->key[len] = '\0';
        printf("%s\n", p->key);
        p->val = _val;
        HASH_ADD_STR(g_hash, key, p);
        return true;
    } else if (p->val != _val) {
        return false;
    }
    return true;
}

int GetHash(const char *s)
{
    Hash *p = NULL;
    HASH_FIND_STR(g_hash, s, p);
    if ( p == NULL) {
        return -1;
    }
    return p->val;
}

void FreeHash()
{
    Hash *cur = NULL;
    Hash *tmp = NULL;
    HASH_ITER(hh, g_hash, cur, tmp) {
        HASH_DEL(g_hash, cur);
        free(cur);
    }
}

int FindLastIndex(const char *s, char c)
{
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

FileSystem* fileSystemCreate() {
    g_hash == NULL;
    FileSystem *file = (FileSystem *)malloc(sizeof(FileSystem));
    if (file == NULL) {
        return NULL;
    }
    memset(file , 0, sizeof(sizeof(FileSystem)));
    return file;
}

bool fileSystemCreatePath(FileSystem* obj, char * path, int value) {
    if (strcmp(path, "/") == 0) {
        return false;
    }
    char tmp[MAXLEN] = {0};
    int index = FindLastIndex(path, '/');
    printf("%d\n", index);
    if (index != 0) {
        Hash *p = NULL;
        strncpy(tmp, path , index);
        tmp[index] = '\0';
        printf("%s\n", tmp);
        HASH_FIND_STR(g_hash, tmp, p) ;
        if (p == NULL) {
            return false;
        }
    }
   
    return  AddHash(path, value);
}

int fileSystemGet(FileSystem* obj, char * path) {
    return GetHash(path);
}

void fileSystemFree(FileSystem* obj) {
    FreeHash();
    free(obj);
}

/**
 * Your FileSystem struct will be instantiated and called as such:
 * FileSystem* obj = fileSystemCreate();
 * bool param_1 = fileSystemCreatePath(obj, path, value);
 
 * int param_2 = fileSystemGet(obj, path);
 
 * fileSystemFree(obj);
*/