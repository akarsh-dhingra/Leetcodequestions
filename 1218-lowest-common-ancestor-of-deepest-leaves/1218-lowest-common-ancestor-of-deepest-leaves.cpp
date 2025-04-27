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
    // int maxDepth(TreeNode* root){
    //     if(root==NULL){
    //         return 0;
    //     }
    //     int leftHeight=maxDepth(root->left);
    //     int rightHeight=maxDepth(root->right);
    //     int ans=max(leftHeight,rightHeight)+1;
    //     return ans;
    // }
    vector<vector<TreeNode*>>levelOrder(TreeNode* root){
        vector<vector<TreeNode*>>temp={};
        if(root==NULL) return temp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int levelSize=q.size();
            vector<TreeNode*>level={};
            for(int i=0;i<levelSize;i++){
               TreeNode*front=q.front();
                q.pop();
                level.push_back(front);
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
            temp.push_back(level);
        }
        return temp;
    }
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<vector<TreeNode*>>temp=levelOrder(root);
        int n=temp.size();
TreeNode* ans = temp[n-1][0];
for(int i = 1; i < temp[n-1].size(); i++) {
    ans = lowestCommonAncestor(root, ans, temp[n-1][i]);
}
return ans;
    }
};