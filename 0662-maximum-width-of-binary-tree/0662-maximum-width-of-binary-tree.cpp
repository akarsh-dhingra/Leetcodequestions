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
    int widthOfBinaryTree(TreeNode* root) {
       queue<pair<TreeNode*,int>>que;
       que.push({root,0});
       int indx=0;
       
       long long ans=0;
       while(!que.empty()){
        int size=que.size();
        int firstIndx=-1;
        int lastIndx=0;
        for(int i=0;i<size;i++){
            TreeNode*front=que.front().first;
            long long indx=que.front().second;
            if(firstIndx==-1) firstIndx=indx;
            else lastIndx=indx;
            que.pop();
            if(front->left){
                que.push({front->left,2*indx+1});
            }
            if(front->right){
                que.push({front->right,2*indx+2});
            }
        }
        if(lastIndx==0) ans=max(ans,1LL);
       else ans=max(ans,abs(lastIndx-firstIndx)+1LL);
       }
        return ans;
    }
};