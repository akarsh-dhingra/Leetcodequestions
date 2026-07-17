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
    void createMapping(vector<int>& inorder,map<int,int>&nodetoIndex,int n){
        for(int i=0;i<n;i++){
            nodetoIndex[inorder[i]]=i;
        }
    }

    TreeNode* createTree(vector<int>& inorder, vector<int>& postorder,map<int,int>&nodetoIndex,int &postOrderIndx,int start,int end,int n){
        if(postOrderIndx<0||start>end) {
            return NULL;
        }
        int curr=postorder[postOrderIndx--];
        TreeNode *node=new TreeNode(curr);
        int posn=nodetoIndex[curr];
        node->right=createTree(inorder,postorder,nodetoIndex,postOrderIndx,posn+1,end,n);
        node->left=createTree(inorder,postorder,nodetoIndex,postOrderIndx,start,posn-1,n);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int postOrderIndx=n-1;
        map<int,int>nodetoIndex;
        createMapping(inorder,nodetoIndex,n);
        return createTree(inorder,postorder,nodetoIndex,postOrderIndx,0,n-1,n);
    }
};