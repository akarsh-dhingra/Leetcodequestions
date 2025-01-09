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
bool validate(TreeNode* &root,long minval,long maxval){
     if(root==NULL){
        return true;
     }
     if(root->val<=minval || root->val>=maxval){
        return false;
     }
     return validate(root->right,root->val,maxval)&&validate    (root->left,minval,root->val);
}
    bool isValidBST(TreeNode* root) {
      return validate(root,LONG_MIN,LONG_MAX);
        
        // vector<int>given;
        // vector<int>temp=inorderTraversal(root);
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     TreeNode*currele=q.front();
        //     given.push_back(currele->val);
        //     if(root->left){
        //         q.push(root->left);
        //     }
        //     else{
        //         q.push(root->right);
        //     }
        // }
        // sort(given.begin(),given.end());
        // if(temp==given){
        //     return true;
        // }
        // return false;
        // // if inorder traversal sa sorted aa rhi hai toh we can comment it is a bst else we cannot
    //     queue<TreeNode*>q;
    //     q.push(root);
    //     while(!q.empty()){
    //         TreeNode*currele=q.front();
    //         if(currele->left){
    //             q.push(currele->left);
    //         }
    //         else{
    //             q.push(currele->right);
    //         }
    //     }
    //     while(!q.empty())
    }
};