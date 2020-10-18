/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 */

// @lc code=start


char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0 || strs[0] == ""){
        return "";
    }
    for(int i = 0; i < strlen(strs[0]); i++){
        for(int j = 1; j < strsSize; j++){
            if(strs[0][i] != strs[j][i]){
                strs[0][i] = '\0';
                break;
            }
        }
    }
    return strs[0];
}


// @lc code=end

