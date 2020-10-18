char * modifyString(char * s){
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] != '?') {
            continue;
        }
        char c = 'a';
        
        while((i - 1 >= 0) && (s[i - 1] == c) || (i + 1 < len) && (s[i + 1] == c)) {
            c++;
        }
        s[i] = c;
    }
    return s;
}