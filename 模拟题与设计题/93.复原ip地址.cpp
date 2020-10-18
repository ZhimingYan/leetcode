// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem93.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
public:
    vector<string> res;//存储的结果
    vector<int> part;  

    vector<string> restoreIpAddresses(string s) {
        dfs(0, 0, s);
        return res;
    }

    // index表示枚举到的字符串下标，nums表示当前截断的IP个数，s表示原字符串
    void dfs(int index, int nums, string &s)
    {
        if(nums > 4) {
            return;
        }
        if (index == s.size()) {
            if (nums == 4) {
                string ip = to_string(part[0]);
                for (int i = 1; i < 4; i++ )
                    ip += '.' + to_string(part[i]);
                res.push_back(ip);
            }
            return;
        }
        unsigned t = 0;//有的案例数字超长顾用无符号数
        for (int i = index; i < s.size(); i++ ) {
            t = t * 10 + s[i] - '0';
            if (t >= 0 && t < 256) {
                part.push_back(t);
                dfs(i + 1, nums + 1, s);
                part.pop_back();
            }
            //这里是排除的是00,01,001等有前导零的数，这类数不合法
            if (!t) {
                break;

            }
        }
    }
};

// @lc code=end

