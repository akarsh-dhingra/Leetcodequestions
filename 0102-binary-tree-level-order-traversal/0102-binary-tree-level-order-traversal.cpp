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
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*>que;
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        que.push(root);
        que.push(NULL);
        
        vector<int>temp;
        
        while(!que.empty()){
            TreeNode*front=que.front();
            que.pop();
            if(front!=NULL){
                temp.push_back(front->val);
                if(front->left) que.push(front->left);
                if(front->right) que.push(front->right);
            }
            else{
               ans.push_back(temp);
               temp={};
              if(!que.empty())que.push(NULL); 
            }
        }
        return ans;
    }
};