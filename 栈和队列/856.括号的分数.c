int scoreOfParentheses(char * S){
    int len = strlen(S);
    int top = 0;
    int *stack = (int *)malloc(len * sizeof(int));
    memset(stack, 0, len * sizeof(int));

    for (int i = 0; i < len; i++) {
        if (S[i] == '(') {
            top++;
        }else{
            top--;
            if (stack[top+1] == 0) {
                stack[top] = stack[top] + 1; 
            }else {
                stack[top] += 2 *stack[top+1];
            }
            stack[top+1]=0;
        }

    }
    int ret = stack[0];
    free(stack);
    return ret;
}