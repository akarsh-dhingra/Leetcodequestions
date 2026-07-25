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
    void solve(vector<vector<int>>&ans,vector<int>temp,int sum,TreeNode* root, int targetSum){
        if(root==NULL) return ;
        sum+=root->val;
        temp.push_back(root->val);

        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                ans.push_back(temp);
                
            }
            return;
        }
        solve(ans,temp,sum,root->left,targetSum);
        solve(ans,temp,sum,root->right,targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
                vector<vector<int>>ans;
                vector<int>temp;
                int sum=0;
                solve(ans,temp,sum,root,targetSum);
                return ans;
    }
};