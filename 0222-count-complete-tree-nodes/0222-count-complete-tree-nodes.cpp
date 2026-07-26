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
    int heightLeft(TreeNode* root){
        if(root==NULL) return 0;
        int height=0;
        TreeNode*temp=root;
        while(temp!=NULL){
            height++;
            temp=temp->left;
        }
        return height;
    }
    int heightRight(TreeNode* root){
        if(root==NULL) return 0;
        int height=0;
        TreeNode*temp=root;
        while(temp!=NULL){
            height++;
            temp=temp->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        int count=0;
        int leftHeight=heightLeft(root);
        int rightHeight=heightRight(root);

        if(leftHeight==rightHeight){
            int formula=(pow(2,leftHeight))-1;
            return formula;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};