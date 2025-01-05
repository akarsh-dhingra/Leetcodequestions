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
void  printrightview(TreeNode* root,int level,vector<int> &rightans){
if(root==NULL){
    return;
}
if(level==rightans.size()){
    rightans.push_back(root->val);
}
printrightview(root->right,level+1,rightans);
printrightview( root->left, level+1,rightans);
}
    vector<int> rightSideView(TreeNode* root) {
       vector<int> rightans;
       printrightview(root,0,rightans);
       return rightans;
    }
};