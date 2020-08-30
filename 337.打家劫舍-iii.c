/*
 * @lc app=leetcode.cn id=337 lang=c
 *
 * [337] 打家劫舍 III
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


#define MAX(a,b) (a>b?a:b)

int *doRob(struct TreeNode* root) {
	int rob[2] = {0};
	if (!root) return rob;
	int* left = doRob(root->left);
	int* right = doRob(root->right);
	rob[0] = MAX(left[0], left[1]) + MAX(right[0] , right[1]);
	rob[1] = root->val + left[0] + right[0];
	return rob;
}
int rob(struct TreeNode* root) {
	int *rob = doRob(root);
	return MAX(rob[0], rob[1]);
}

int rob(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }

    int haveRoot = root->val;
    if (root->left) {
        haveRoot += rob(root->left->left);
        haveRoot += rob(root->left->right);
    }
    if (root->right) {
        haveRoot += rob(root->right->left);
        haveRoot += rob(root->right->right);
    }

     int haveNoRoot = 0;
     haveNoRoot += rob(root->left);
     haveNoRoot += rob(root->right);

     return (haveRoot > haveNoRoot ? haveRoot : haveNoRoot);
}

// @lc code=end

