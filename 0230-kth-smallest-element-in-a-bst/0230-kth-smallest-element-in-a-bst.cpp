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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>temp={};
        if(root==NULL){
            return temp;
        }
        vector<int>left=inorderTraversal(root->left);
        vector<int>right=inorderTraversal(root->right);
        temp.insert(temp.end(),left.begin(),left.end());
        temp.push_back(root->val);
        temp.insert(temp.end(),right.begin(),right.end());
        return temp;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>sorted=inorderTraversal(root);
        return sorted[k-1];
        // if(root==NULL){
        //     return 0;
        // }
        // TreeNode*temp=root;
        // queue<TreeNode*>q;
        // q.push(temp);
        // while(temp->left){
        //     q.push(temp->left);
        // }
        // int kthsmallest=q.size()-k;
        // while(kthsmallest!=0){
        //     q.pop();
        // }
        // TreeNode*ansNode=q.front();
        // return ansNode->val;
    }
};