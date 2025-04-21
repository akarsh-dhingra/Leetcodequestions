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
    int maxDepth(TreeNode* root) {
        // ak case solve krta hu jisme koi node hee nahi h
        if(root==NULL){
            return 0;
        }
        // No. of levels= depth of BT.
        int leftHeight=maxDepth(root->left); 
        int rightHeight=maxDepth(root->right);
        int maxlen=max(leftHeight,rightHeight)+1;
        return maxlen;
    }
};