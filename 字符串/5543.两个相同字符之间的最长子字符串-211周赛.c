

int maxLengthBetweenEqualCharacters(char * s){
    int len = strlen(s);
    int max = -1;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j]) {
                max = j - i - 1 > max? j - i - 1 : max;
                //break;
            } 
        }    
    }
    return max;
}