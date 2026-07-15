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
      vector<vector<int>>ans;
       vector<int>temp;
       queue<TreeNode*>que;
       if(root==NULL) return ans;
        que.push(root);
        bool leftToRight=false;
       while(!que.empty()){
        int size=que.size();
        vector<int>temp(size);
        for(int i=0;i<size;i++){
            TreeNode* front=que.front();
            que.pop();

            int index=leftToRight?i:size-i-1;

            temp[index]=front->val;
            if(front->right){
                que.push(front->right);
            }
            if(front->left){
                que.push(front->left);
            }
        }    
        ans.push_back(temp);
        leftToRight=!leftToRight;    
       }
       return ans;
    }
};