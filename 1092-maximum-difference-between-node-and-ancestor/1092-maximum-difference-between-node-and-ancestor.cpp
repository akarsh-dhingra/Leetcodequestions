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
int maxDiff(TreeNode* root,int maxVal,int minVal,int ans){
    if(root==NULL) return max(ans,maxVal-minVal);
    maxVal=max(maxVal,root->val);
    minVal=min(minVal,root->val);
    ans=maxVal-minVal;
   int leftAns= maxDiff(root->left,maxVal,minVal,ans);
   int rightAns=maxDiff(root->right,maxVal,minVal,ans);

   return max(leftAns,rightAns);

}
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return maxDiff(root,root->val,root->val,0);
    }
};