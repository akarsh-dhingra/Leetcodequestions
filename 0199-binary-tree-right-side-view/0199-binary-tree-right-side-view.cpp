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
    vector<int> levelordertraversalrightview(TreeNode* root){
        vector<int>temp;
        if(root==NULL){
            return temp;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        temp.push_back(root->val);
        while(!q.empty()){
            TreeNode*currele=q.front();
            q.pop();
            if(currele==NULL){
                if(!q.empty()){
                TreeNode*ele=q.front();
                temp.push_back(ele->val);
                q.push(NULL);
            }
            else {}
            }
            else{
                if(currele->right!=NULL){
                    q.push(currele->right);
                }
                if(currele->left!=NULL){
                    q.push(currele->left);
                }  
            }
        }
        return temp;
    }
    vector<int> rightSideView(TreeNode* root) {
       vector<int>a=levelordertraversalrightview(root);
       return a;
    }
};