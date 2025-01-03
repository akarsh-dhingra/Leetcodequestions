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
int maxdepth(TreeNode* root){
if(root==NULL){
    return 0;
}
int left=maxdepth(root->left);
int right=maxdepth(root->right);
int ans=max(left,right)+1;
return ans;
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int heightLeft=maxdepth(root->left);
        bool leftans=isBalanced(root->left);
        int heightRight=maxdepth(root->right);
        bool rightans=isBalanced(root->right);
        int diff=abs(heightLeft-heightRight);
        bool currnoans=(diff<=1);
        if(currnoans&&rightans&&leftans){
         return true;
        }
        else return false;
    }
};