#define MAX 1000001

typedef struct {
    int val[MAX];
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap *ret = (MyHashMap *)malloc(sizeof(MyHashMap));
    if (ret == NULL) {
        return NULL;
    }
    for (int i = 0; i < sizeof(ret->val) / sizeof(ret->val[0]); i++) {
        ret->val[i] = -1;
    }

    return ret;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    //if (key < 0 || key > MAX)
     //   return;
    //printf("key:%d  val:%d\n", key, value);
    obj->val[key] = value;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    //if (key < 0 || key > MAX)
    //    return -1;
    return obj->val[key];
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    //if (key < 0 || key > MAX)
     //   return;
    //printf("key:%d\n", key);
    obj->val[key] = -1;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/

