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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>temp={};
        if(root==NULL){
            return temp;
        }
        vector<int>left=postorderTraversal(root->left);
        vector<int>right=postorderTraversal(root->right);
        temp.insert(temp.end(),left.begin(),left.end());
        temp.insert(temp.end(),right.begin(),right.end());
         temp.push_back(root->val);
        return temp;
    }
};