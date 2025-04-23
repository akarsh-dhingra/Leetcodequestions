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
void getpath(TreeNode* root,vector<string>&ans,string currpath){
    if(root==NULL) return;
    
    if(root->left==NULL && root->right==NULL){
        currpath+=to_string(root->val);
        ans.push_back(currpath);
        return;
    }
    currpath+=to_string(root->val)+"->";
   if(root->left) getpath(root->left,ans,currpath);
   if(root->right) getpath(root->right,ans,currpath);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root==NULL){
            return ans;
        }
        getpath(root,ans,"");
        return ans;
        // 
    }
};