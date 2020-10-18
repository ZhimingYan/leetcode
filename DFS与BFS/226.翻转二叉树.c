/*
 * @lc app=leetcode.cn id=226 lang=c
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* invertTree(struct TreeNode* root){
    if(NULL == root) {
        return NULL;
    }
    struct TreeNode *right = invertTree(root->right);
    struct TreeNode *left = invertTree(root->left);
    root->left = right;
    root->right = left;
    return root;
}


// @lc code=end

