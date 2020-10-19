bool buddyStrings(char * A, char * B){
    int cntA = 0,cntB = 0,ch,cnt = 0,cnt2 = 0;
    int tempA[26] = {0},tempB[26] = {0};
    //统计A和B字符总数和每个字符的个数
    for(int i = 0;A[i] != '\0';i++)
    {
        ch = A[i] - 'a';
        tempA[ch]++;
        cntA++;
    }
    for(int i = 0;B[i] != '\0';i++)
    {
        ch = B[i] - 'a';
        tempB[ch]++;
        cntB++;
    }
    //分类讨论，如果字符总数不相等，肯定不满足
    if(cntA != cntB) return false;
    //之后再判断每个字符的个数相不相同，不相同也不满足，同时记录出现次数超过2的字符个数
    for(int i = 0;i < 26;i++)
    {
        if(tempA[i] != tempB[i]) return false;
        if(tempA[i] >= 2) cnt2++;
    }
    //满足以上条件，再判断A和B中位置不同的字符个数
    for(int i = 0;i < cntA;i++)
    {
        if(A[i] != B[i]) cnt++;
    }
    //如果满足以上条件，且位置不同的字符个数是2，那么就可以调换这两个字符的位置达到题目要求
    //或者两个字符串一模一样，那就要看看每个字符出现的次数，如果都为1，说明每个字符各不相同，则不满足
    //当有至少一个字符出现两次，那么就可以通过调换两个相同的字符，使得字符串不变来满足题目条件
    if(cnt == 2 || (cnt == 0 && cnt2 >= 1)) return true;
    return false;

}
