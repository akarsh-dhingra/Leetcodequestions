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
    void solve(vector<string>&ans,string temp,TreeNode* root){
        if(root==NULL) return;
        temp+=(to_string(root->val));
        
        if(root->left==NULL && root->right==NULL){
            ans.push_back(temp);
            return;
        }
        temp+='-';
        temp+='>';
        solve(ans,temp,root->left);
        solve(ans,temp,root->right);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp="";
        solve(ans,temp,root);
        return ans;
    }
};