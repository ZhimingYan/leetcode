int numWays(char * s){
    if(s == NULL) {
        return 0;
    }
    int count = 0;
    int len = strlen(s);
    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        if(s[i] == '1') {
            count++;
        }
    }
    if (count == 0 && len > 3) {
        return (long long)(len - 1) * (len - 2) / 2 % 1000000007;
    }
    if (count == 0 || count % 3 != 0) {
        return 0;
    }

    int num = count / 3; //每个子串含有1的个数
    printf("%d\n", num);
    int first = 0;
    int last = len - 1;
    int count1 = 0;
    int count2 = 0;
    while (count1 != num) {
        if (s[first] == '1') {
            count1++;
        }
        first++;
    }
     printf("%d\n", first);
    while (count2 != num) {
        //printf("%d\n", last);
        if (s[last] == '1') {
            count2++;
        }
        last--;
    }
    printf("%d %d\n", first, last);
    
    int lastZero = 0;
    int firstZero = 0;
    while (s[first] == '0') {
        first++;
        firstZero++;
    }
    while (s[last] == '0') {
        last--;
        lastZero++;
    }
    printf("%d %d\n", lastZero ,firstZero);
    long long res = (long long)(lastZero + 1) * (firstZero + 1);
    return res % 1000000007 ;
}