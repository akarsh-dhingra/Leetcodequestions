/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      // NULL
      if(root==NULL) return NULL;
      // it is used for cases 2-6 or 
      // it is used for finding the root pa and q whose lca we have to find later on jinhe backtrack we'll find lca
      if(root==p||root==q) return root; 
      // intution behind leftNode and RightNode is ki two cases can exist both lie in the same subtree or diff
      TreeNode*leftAns=lowestCommonAncestor(root->left,p,q);
      TreeNode*rightAns=lowestCommonAncestor(root->right,p,q);

      if(leftAns!=NULL&&rightAns!=NULL){
        return root;
      }
     else if(leftAns!=NULL&&rightAns==NULL){
        return leftAns;
      }
      else if(leftAns==NULL&&rightAns!=NULL){
        return rightAns;
      }
      else{
        return NULL;
      }
    }
};