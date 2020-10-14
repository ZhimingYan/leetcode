#define MAXLEN 100

char g_stack[MAXLEN];
int g_stackLen;

int GetMax(int a, int b)
{
    return a > b ? a : b;
}

int maxDepth(char * s){
    memset(g_stack, 0, sizeof(g_stack));
    g_stackLen = 0;
    int len = strlen(s);
    int max = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            g_stack[g_stackLen++] = '(';
        }
        if (s[i] == ')') {
            if (g_stackLen == 0) {
                return 0;
            }
            max = GetMax(max, g_stackLen );
            g_stackLen--;
        }
    }
    if (g_stackLen != 0) {
        return 0;
    }
    return max;
}