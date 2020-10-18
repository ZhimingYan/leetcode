
/*
暴力法做，会导致一个测试用例超时
*/
#define MAXLEN 100000

typedef struct {
    int queue[MAXLEN];
    int index;
} Fancy;


Fancy* fancyCreate() {
    Fancy *obj = (Fancy *)malloc(sizeof(Fancy));
    memset(obj->queue, 0, sizeof(obj->queue));
    obj->index = 0;
    return obj;
}

void fancyAppend(Fancy* obj, int val) {
    
    obj->queue[obj->index] = val;
    obj->index++;
}

void fancyAddAll(Fancy* obj, int inc) {
    for (int i = 0; i < obj->index; i++) {
        obj->queue[i] += inc;
    }
}

void fancyMultAll(Fancy* obj, int m) {
    for (int i = 0; i < obj->index; i++) {
        obj->queue[i] = (obj->queue[i] * (long)m) % 1000000007;
    }
}

int fancyGetIndex(Fancy* obj, int idx) {
    if (idx < obj->index) {
        return obj->queue[idx];
    }
    return -1;
}

void fancyFree(Fancy* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

/**
 * Your Fancy struct will be instantiated and called as such:
 * Fancy* obj = fancyCreate();
 * fancyAppend(obj, val);
 
 * fancyAddAll(obj, inc);
 
 * fancyMultAll(obj, m);
 
 * int param_4 = fancyGetIndex(obj, idx);
 
 * fancyFree(obj);
*/

/*
以下是数学的做法，膜拜大佬
*/

#define LL long long

class Fancy {
private:
    vector<LL> nums;
    LL add, mul;
    const int mod = 1000000007;

    LL power(LL x, int y) {
        LL tot = 1, p = x;
        for (; y; y >>= 1) {
            if (y & 1)
                tot = (tot * p) % mod;
            p = (p * p) % mod;
        }
        return tot;
    }

public:
    Fancy() {
        add = 0;
        mul = 1;
    }

    void append(int val) {
        val = ((val - add) % mod + mod) % mod;
        val = (val * power(mul, mod - 2)) % mod;
        nums.push_back(val);
    }

    void addAll(int inc) {
        add = (add + inc) % mod;
    }

    void multAll(int m) {
        add = add * m % mod;
        mul = mul * m % mod;
    }

    int getIndex(int idx) {
        if (idx >= nums.size())
            return -1;
        return (nums[idx] * mul + add) % mod;
    }
};

作者：wzc1995
链接：https://www.acwing.com/solution/content/22796/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。