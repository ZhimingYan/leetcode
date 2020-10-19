void Modify(char *s)
{
    int n = strlen(s);
    char *stack = (char *)malloc(sizeof(char) * (n + 1));
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '#') {
            stack[index++] = s[i];
        }
        if (s[i] == '#' && index != 0) {
            index--;
        }
    }
    stack[index] = '\0';
    strcpy(s, stack);
}

bool backspaceCompare(char * S, char * T){

    Modify(S);
    Modify(T);

    printf("%s\n", S);
    printf("%s\n", T);
    return !strcmp(S, T);
}