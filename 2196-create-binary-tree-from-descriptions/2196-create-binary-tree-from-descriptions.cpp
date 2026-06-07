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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // In binary tree each node can have atmost two values with it 
        // for any node assign it's left and right children 
        // for each triplet identify the parent-child relationship

        // using a map to link each parent to it's children 
        
        unordered_set<int>childSet;
        unordered_map<int,TreeNode*>mp;

        for(vector<int>&it:descriptions){
            int parent=it[0];
            int child=it[1];
            int leftChild=it[2];

            if(mp.find(parent)==mp.end()){
                mp[parent]=new TreeNode(parent);
            }
            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }

            if(leftChild==1){
                mp[parent]->left=mp[child];
            }
            if(leftChild==0){
                mp[parent]->right=mp[child];
            }
            childSet.insert(child);
        }

        // Now find the root

        for(vector<int>&it:descriptions){
            if(childSet.find(it[0])==childSet.end()){
                return mp[it[0]];
            }
        }
        return NULL;
    }
};