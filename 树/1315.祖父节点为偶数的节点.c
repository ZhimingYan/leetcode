/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int sumEvenGrandparent(struct TreeNode* root){
    int sum = 0;
    if(!root)
    return 0;
    if(!root->left && !root->right)
    return 0;
    if(root->val % 2 != 0)
    return sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
    else{
        if(root->left){
            if(root->left->left)
            sum += root->left->left->val;
            if(root->left->right)
            sum += root->left->right->val;
        }
        if(root->right){
            if(root->right->left)
            sum += root->right->left->val;
            if(root->right->right)
            sum += root->right->right->val;
        }
        return sum + sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
    }
}
