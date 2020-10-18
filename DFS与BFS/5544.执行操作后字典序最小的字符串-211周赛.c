void plus(char *s, int a)
{
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (i % 2 == 1) {
            if (s[i] - '0' + a > 9) {
                s[i] = '0';
                continue;
            } 
            s[i] = s[i] + a;
        }
    }
}

void update(char *c, int a)
{
    *c = '0' + (*c - '0' + a) % 10;
}

void move(char *s, int b)
{
    int len = strlen(s);
    char *tmp = (char *)malloc(sizeof(char) * (len + 1));
    int index = 0;
    for (int i = b; i < len; i++) {
        tmp[index++] = s[i];
    }
    for (int j = 0; j < b; j++){
        tmp[index++] = s[j];
    }
    tmp[index] = '\0';
    strcpy(s, tmp);
}
char * findLexSmallestString(char * s, int a, int b){
    int len = strlen(s);
    char *tmp = (char *)malloc(sizeof(char) * (len + 1));
    strcpy(tmp,s);
    if (b % 2 == 0) {
        for (int i = 0; i < 10; i ++) {
            for (int j = 1; j < len; j += 2) update(&s[j], a);
            for (int j = 0; j < len; j++) {
                move(s, b);
                if (strcmp(s, tmp) < 0) {
                    strcpy(tmp, s);
                }
            }
        }
    } else {
        for (int i = 0; i < 10; i++) {
            for (int j = 1; j < len; j += 2) update(&s[j], a);
            for (int j = 0; j < 10; j++) {
                for (int j = 0; j < len; j += 2) update(&s[j], a);
                for (int j = 0; j < len; j++) {
                    move(s, b);
                    if (strcmp(s, tmp) < 0) {
                        strcpy(tmp, s);
                    }
                }
            }
        }
    }
    return tmp;
}


/*
以下是通过BFS来做
*/

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;//记录已经出现的状态
        string cur, nt, minstr = s;
        int i, n = s.size(), bit;
        vis.insert(s);
        queue<string> q;
        q.push(s);
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            if(cur < minstr)
                minstr = cur;
            nt = cur;
            for(i = 1; i < n; i+=2)
            {	//奇数位加 a
                bit = (cur[i]-'0'+a)%10;
                nt[i] = bit+'0';
            }
            if(!vis.count(nt))
            {
                vis.insert(nt);
                q.push(nt);
            }
            // 向右轮转
            nt = cur.substr(n-b)+cur.substr(0,n-b);
            if(!vis.count(nt))
            {
                vis.insert(nt);
                q.push(nt);
            }
        }
        return minstr;
    }
};
