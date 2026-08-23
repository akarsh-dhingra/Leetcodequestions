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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool flag=true;
        vector<int>temp;
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>que;
        que.push(root);
        que.push(NULL);

        while(!que.empty()){
            TreeNode *front=que.front();
            que.pop();

            if(front!=NULL){
                temp.push_back(front->val);
                if(front->left) que.push(front->left);
                if(front->right) que.push(front->right);
            }
            else{
                if(flag==false){
                    reverse(temp.begin(),temp.end());
                }
                ans.push_back(temp);
               if(!que.empty()) que.push(NULL);
                temp={};
                flag=!flag;
            }
        }
        return ans;
    }
};