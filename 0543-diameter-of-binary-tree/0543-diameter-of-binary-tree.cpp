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
    int maxHeight(TreeNode* root){
        if(root==NULL) return 0;
        int o1=maxHeight(root->left);
        int o2=maxHeight(root->right);
        return max(o1,o2)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
               if(root==NULL) return 0;
               int op1=diameterOfBinaryTree(root->left);
               int op2=diameterOfBinaryTree(root->right);
               int op3=maxHeight(root->left)+maxHeight(root->right);

               return max(op1,max(op2,op3));
    }
};