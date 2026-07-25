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
    bool solve(int sum,TreeNode* root,int targetSum){
        if(root==NULL) return false;
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum) return true;
        }
        
        bool leftAns=solve(sum,root->left,targetSum);
        bool rightAns=solve(sum,root->right,targetSum);
        return leftAns|rightAns;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        int sum=0;
        return solve(sum,root,targetSum);
    }
};