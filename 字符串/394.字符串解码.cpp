// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem394.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
     string res;
        for (int i = 0; i < s.size();)
        {
            if (!isdigit(s[i])) res += s[i ++ ];
            else
            {
                int j = i;
                while (isdigit(s[j])) j ++ ;
                int t = atoi(s.substr(i, j - i).c_str());
                int k = j + 1, sum = 0;
                while (sum >= 0)
                {
                    if (s[k] == '[') sum ++ ;
                    if (s[k] == ']') sum -- ;
                    k ++ ;
                }
                string str = decodeString(s.substr(j + 1, k - j - 2));
                while (t -- ) res += str;
                i = k;
            }
        }
        return res;
    }
};
// @lc code=end

