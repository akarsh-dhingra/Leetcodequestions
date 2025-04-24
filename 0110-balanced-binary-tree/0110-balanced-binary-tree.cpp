/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int heightTree(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int leftTree=heightTree(root->left);
    int rightTree=heightTree(root->right);
    int ans=max(rightTree,leftTree)+1;
    return ans;
}
    bool isBalanced(TreeNode* root) {
     if(root==NULL) return true;
if(isBalanced(root->left)&&isBalanced(root->right)){
    if(abs(heightTree(root->left)-heightTree(root->right))<=1){
        return true;
    }
}
        return false;
    }
};