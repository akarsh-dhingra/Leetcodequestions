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
        vector<vector<int>>temp;
    if(root==NULL){
        return temp;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int levelsize=q.size();
        vector<int>level;
        for(int i=0;i<levelsize;i++){
            // Every instance level will be empty 
            // we will create a node of queue's initial element
            TreeNode*currele=q.front();
            q.pop();
            level.push_back(currele->val);
            if(currele->left) q.push(currele->left);
            if(currele->right) q.push(currele->right);
        }
        temp.push_back(level);
    }
    return temp;     
    }
};