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
        if(root==NULL){
            return 0;
            }
        int rightlen=maxDepth(root->right);
        int leftlen=maxDepth(root->left);
        int maxlen=max(rightlen,leftlen)+1;
        return maxlen;
    }
    int diameterOfBinaryTree(TreeNode* root){
        // in right subtree;
        // in left subtree;
        // in both subtrees;
        if(root==NULL){
            return 0;
        }
        int option1=diameterOfBinaryTree(root->left);
        int option2=diameterOfBinaryTree(root->right);
        int option3=maxDepth(root->left)+maxDepth(root->right);
        int ans=max(option1,max(option2,option3));
        return ans;
    }
};