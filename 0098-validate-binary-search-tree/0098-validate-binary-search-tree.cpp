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
    bool checkKrLe(TreeNode* root, long long  maxi,long long mini){
        if(root==NULL){
            return true;
        }
        if(root->val>mini && root->val<maxi){
            bool left=checkKrLe(root->left,root->val,mini);
            bool right=checkKrLe(root->right,maxi,root->val);
            return left && right;
        }
        else 
            return false;
    }
    bool isValidBST(TreeNode* root) {
        return checkKrLe(root,LLONG_MAX,LLONG_MIN);
    }
};