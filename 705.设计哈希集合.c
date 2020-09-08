#define MAXN 1000000
typedef struct {
    bool val[MAXN];
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet *obj = (MyHashSet *)malloc(sizeof(MyHashSet));
    memset(obj, 0, sizeof(MyHashSet));
    if (obj == NULL) {
        return NULL;
    }
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if (obj->val[key] == true) {
        return;
    }
    obj->val[key] = true;
    return;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    if (obj->val[key]) {
        obj->val[key] = false;
    }
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->val[key];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/