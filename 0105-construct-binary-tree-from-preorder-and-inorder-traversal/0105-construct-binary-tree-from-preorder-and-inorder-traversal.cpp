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
    int findInorder(int x,vector<int>& inorder){
        for(int i=0;i<inorder.size();i++){
            if(x==inorder[i]) return i;
        }
        return -1;
    }
    TreeNode* createNode(vector<int>& preorder, vector<int>& inorder,int &preOrderIndx,int start,int end,int n){
            if(preOrderIndx>=n||start>end ){
                return NULL;
            }
            // create current Node;
            int crr=preorder[preOrderIndx++];
            TreeNode *root=new TreeNode(crr);
            int posn=findInorder(crr,inorder);
            root->left=createNode(preorder,inorder,preOrderIndx,start,posn-1,n);
            root->right=createNode(preorder,inorder,preOrderIndx,posn+1,end,n);

            return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // inorder-> LNR
        // preorder-> NLR
        int n=preorder.size();
        int preOrderIndx=0;
        int start=0;
        int end=n-1;
        return createNode(preorder,inorder,preOrderIndx,start,end,n);
    }
};