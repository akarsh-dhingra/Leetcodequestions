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
        // Ultimately we've to find distance between two nodes
        // that are at the extreme levels 
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long>>que;
        que.push({root,0});
        int ans=0;
        while(!que.empty()){
            // hum har level ka saare mai sa MinIndx nikal lenge usse fir aage jaane vaale Indexes 
            // ko update krte jayenge 
            int size=que.size();
            long long mIndx=que.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                long long curr_id=que.front().second-mIndx;
                TreeNode*node=que.front().first;
                que.pop();
                if(i==0) first=curr_id;
                if(i==size-1) last=curr_id;
                if(node->left) que.push({node->left,2*curr_id+1});
                if(node->right) que.push({node->right,2*curr_id+2});
            }
        ans=max(ans,last-first+1);
        }
        return ans;
    }
};