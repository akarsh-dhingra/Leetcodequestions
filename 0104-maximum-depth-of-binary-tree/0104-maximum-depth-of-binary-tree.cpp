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
    int maxDepth(TreeNode* root) {
  queue<TreeNode*>q;
  q.push(root);
  if(root==NULL){
    return 0;
  }
  q.push(NULL);
  int cnt=1;
  while(q.size()>1){
    TreeNode*front=q.front();
    q.pop();
    if(front==NULL){
      if(!q.empty()){
        cnt++;
        q.push(NULL);
      }
    }
    else{
      if(front->left!=NULL){
        q.push(front->left);
      }
      if(front->right!=NULL){
        q.push(front->right);
      }
    }
  }
        return cnt;
    }
};