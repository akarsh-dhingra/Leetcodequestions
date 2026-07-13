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
       vector<vector<int>>ans;
       vector<int>temp;
       queue<TreeNode*>que;
       if(root==NULL) return ans;
        que.push(root);
        que.push(NULL);
       while(!que.empty()){
        TreeNode*top=que.front();
        que.pop();

        if(top==NULL){
            ans.push_back(temp);
            temp={};
            if(!que.empty()){
                que.push(NULL);
            }
        }
        else{
            temp.push_back(top->val);
            if(top->left){
                que.push(top->left);
            }
            if(top->right){
                que.push(top->right);
            }
        }
       }
       return ans;
    }
};