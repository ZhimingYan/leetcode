// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem961.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 重复 N 次的元素
 */

// @lc code=start

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for(int i = 0; i < A.size(); i += 2){
            if(A[i] == A[i+1]){
                return A[i];
            }
        }
        if(A[0] == A[2] || A[0] == A[3]){
            return A[0];
        }
        return A[1];
    }
};
// @lc code=end

