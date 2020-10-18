/*
 * @lc app=leetcode.cn id=961 lang=c
 *
 * [961] ?? N ????
 */

// @lc code=start


int repeatedNTimes(int* A, int ASize){
        for(int i = 0; i < ASize; i += 2){
            if(A[i] == A[i+1]){
                return A[i];
            }
        }
        if(A[0] == A[2] || A[0] == A[3]){
            return A[0];
        }
        return A[1];
}


// @lc code=end

