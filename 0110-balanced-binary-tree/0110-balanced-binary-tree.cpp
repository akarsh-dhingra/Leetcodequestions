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
    int heightBt(TreeNode* root){
        if(root==NULL) return 0;
        int leftTree=heightBt(root->left);
        int rightTree=heightBt(root->right);
        return max(leftTree,rightTree)+1;   
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        if(isBalanced(root->left)&&isBalanced(root->right)){
            if(abs(heightBt(root->left)-heightBt(root->right))<=1){
                return true;
            }
        }
        return false;
    }
};