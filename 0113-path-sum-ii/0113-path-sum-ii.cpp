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
  void solve(TreeNode* root, int sum, vector<vector<int>>&answer,vector<int>&temp, int targetSum){
    if(root==NULL){
        return;
    }
    sum+=root->val;
    temp.push_back(root->val);
    if(root->left==NULL && root->right==NULL){
        if(sum==targetSum){
            answer.push_back(temp);
        }
    }
   else{ 
    solve(root->left,sum,answer,temp,targetSum);
    solve(root->right,sum,answer,temp,targetSum);
   }
   temp.pop_back();
  }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      int sum=0;
      vector<vector<int>>answer;
      vector<int>temp={};
      solve(root,sum,answer,temp,targetSum);
      return answer;
    }
};