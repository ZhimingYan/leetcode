#define MAXLEN 10000

char * removeOuterParentheses(char * S){
    int len = strlen(S);
    int stack[MAXLEN] = {0};
    int index = 0;
    int i = 1;
    int j = 0;
    
    char *res = (char *)malloc(sizeof(char) * MAXLEN);
    while (i < len - 1) {
        if (S[i] == '(') {
            stack[index++] = '(';
            res[j++] = '(';
        } else {
            if (index > 0) {
                index--;
                res[j++] = ')';
            } else if (index == 0) {
                i++;
            }
        }
        i++;
    }
    
    res[j] = '\0';
    
    return res;
                            
}