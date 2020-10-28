## LeetCode 25. $k$ 个一组翻转链表

**[原题链接](https://leetcode.com/problems/reverse-nodes-in-k-group/description/) 【hard】** 

#### 题目描述

给定一个字符串 `s` 和含有单词的数组 `words`，其中数组中的每个单词长度都是相同的。

找到所有 `s` 子串开始的下标，使得该子串是所有单词数组中单词的组合拼接（每个单词仅出现一次，且不得有重叠覆盖）。

**示例：**

~~~
输入：
  s = "barfoothefoobarman",
  words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar"。
输出的顺序不重要, [9,0] 也是有效答案。
~~~

~~~
输入：
s = "wordgoodstudentgoodword",
words = ["word","student"]
输出：[]
~~~



#### 算法

**(暴力枚举）** $O(n⋅len)$ 

1. 假设 `s` 的长度为 `n`，单词的长度为 `len`，单词的个数为 `tot`。
2. 由于数组中每个单词长度都是相同的，故可以按照单词的长度 `len` 来将 `s `划分为 `len` 种候选单词序列。举例来看 `barfoothefoobarman`，根据单词长度为 3，可以得到 3 种不同的划分，分别是 `bar foo the foo bar man`、`arf oot hef oob arm an` 和 `rfo oth efo oba rma n `三种。
3. 对于以上的每一种划分来说，仅需要用 `unordered_map` 就可以暴力的算出来，能否能由单词列表中的所有单词拼接而成。具体见代码。

**时间复杂度**

- 划分种类是 $O(len)$ 种方法，每次需要 $O(n)$ 的时间寻找匹配，故总时间复杂度为 $O(n⋅len)$。

**C++代码**

~~~cpp
class Solution {
public:
    int check(string s, int begin, int n, int len, int tot,
            unordered_map<string, int>& wc, vector<int>& ans) {
        // 寻找以begin开始的子串的所有匹配，并返回下一次开始匹配的位置。

        unordered_map<string, int> vis;
        int count = 0;
        for (int i = begin; i < n - len + 1; i += len) {
            string candidate = s.substr(i, len);
            if (wc.find(candidate) == wc.end())
                // 遇到不合法的候选单词，直接返回下一次的开始位置为i+len。
                return i + len;

            while (vis[candidate] == wc[candidate]) {
                // 遇到多余的候选单词，不断从begin开始删除候选单词，直到当前候选单词合法。
                vis[s.substr(begin, len)]--;
                count--;
                begin += len;
            }
            vis[candidate]++; // 插入候选单词。
            count++;
            if (count == tot) // 找到一个位置，记录答案。
                ans.push_back(begin);
        }
        return n;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.length();
        int tot = words.size();
        if (tot == 0) return ans;

        unordered_map<string, int> wc;

        for(int i = 0; i < tot; i++)
            wc[words[i]]++;
        int len = words[0].length();

        for (int offset = 0; offset < len; offset++) // 枚举划分
            for (int begin = offset; begin < n;
                begin = check(s, begin, n, len, tot, wc, ans));

        return ans;
    }
};
~~~

