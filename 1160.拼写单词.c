/*
 * @lc app=leetcode.cn id=1160 lang=c
 *
 * [1160] 拼写单词
 */

// @lc code=start


int g_hash[26];

int countCharacters(char ** words, int wordsSize, char * chars){ 
    (void)memset(g_hash, 0, sizeof(g_hash));

    int len = strlen(chars);
    for (int i = 0; i < len; i++) {
        g_hash[chars[i] - 'a']++;
    }

    int res  = 0;
    int count;
    int hash[26] = {0};
    for (int i = 0; i < wordsSize; i++) {
        memset(hash, 0,sizeof(hash));
        int wordsLen = strlen(words[i]);
        for (int j = 0; j < wordsLen; j++) {  
            hash[words[i][j] - 'a']++;
        }
        for (int j = 0; j < wordsLen; j++) {  
            if (hash[words[i][j] - 'a'] > g_hash[words[i][j] - 'a']) {
                break;
            }
            if (j == wordsLen - 1) {
                res += wordsLen; 
            }
        }
    }
    return res;
}

// @lc code=end

