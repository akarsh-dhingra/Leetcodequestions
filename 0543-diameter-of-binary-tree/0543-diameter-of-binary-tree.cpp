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
    pair<int,int>diameterFast(TreeNode* root){
        // pehle mai diameter dusre mai height 
        // diameter is number of edges 
        if(root==NULL) {
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        pair<int,int>p1=diameterFast(root->left);
        pair<int,int>p2=diameterFast(root->right);

        int op1=p1.first;
        int op2=p2.first;
        int op3=p1.second+p2.second;
        pair<int,int>ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(p1.second,p2.second)+1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
              return diameterFast(root).first;
    }
};