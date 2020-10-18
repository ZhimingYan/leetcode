#define MAXSTEP 101
#define MAXLEN 21
typedef struct {
    char stack[MAXSTEP][MAXLEN];
    int top;
    int cur;
} BrowserHistory;


BrowserHistory* browserHistoryCreate(char * homepage) {
    BrowserHistory *obj = (BrowserHistory *)malloc(sizeof(BrowserHistory));
    if (obj == NULL) {
        return NULL;
    }
    memset(obj, 0, sizeof(BrowserHistory));
    if (homepage != NULL) {
        strcpy(obj->stack[obj->cur], homepage);
        obj->top = obj->cur + 1;
    }
    return obj;
}

void browserHistoryVisit(BrowserHistory* obj, char * url) {
    if (url == NULL) {
        return;
    }
    strcpy(obj->stack[++obj->cur],url);
    obj->top = obj->cur + 1;  
}

char * browserHistoryBack(BrowserHistory* obj, int steps) {
    steps = steps > obj->cur ? obj->cur : steps;
    int tmp = obj->cur - steps;
    obj->cur = obj->cur - steps;
    return obj->stack[tmp];
    
}

char * browserHistoryForward(BrowserHistory* obj, int steps) {
    steps = steps > obj->top - obj->cur - 1? obj->top - obj->cur-1 : steps;
    int tmp = obj->cur + steps;
    obj->cur = obj->cur + steps;
    return obj->stack[tmp];
}

void browserHistoryFree(BrowserHistory* obj) {
    if (obj != NULL) {
        free(obj);
    }      
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);
 
 * char * param_2 = browserHistoryBack(obj, steps);
 
 * char * param_3 = browserHistoryForward(obj, steps);
 
 * browserHistoryFree(obj);
*/