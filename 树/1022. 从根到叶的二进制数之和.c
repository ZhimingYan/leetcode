/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void dfs(struct TreeNode* root, int cur, int *sum)
{
	if (root == NULL) {
		return;
	}
	cur = cur * 2 + root->val;
	if (root->left == NULL && root->right == NULL) {
		*sum = (*sum + cur) % (1000000007);
		return;
	}
	dfs(root->left, cur, sum);
	dfs(root->right, cur, sum);
	return;
}
int sumRootToLeaf(struct TreeNode* root){
	int sum = 0;
	dfs(root, 0, &sum);
	return sum;
}

