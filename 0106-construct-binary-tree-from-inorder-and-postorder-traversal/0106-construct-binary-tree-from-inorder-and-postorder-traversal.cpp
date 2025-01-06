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
TreeNode* constructbinarytreefrominorderandpostordertraversal(vector<int>& postorder, vector<int>& inorder,int inorderstart,int &postorderIndx,int inorderend,int size,unordered_map<int,int>&valuetoindexmap){
if(postorderIndx<0||inorderstart>inorderend){
    return NULL;
}
// Step 1:
int element=postorder[postorderIndx];
postorderIndx--;
// Step 2:
TreeNode*root=new TreeNode(element);
int posn=valuetoindexmap[element];
root->right=constructbinarytreefrominorderandpostordertraversal(postorder, inorder, posn+1, postorderIndx,inorderend,size,valuetoindexmap);
root->left=constructbinarytreefrominorderandpostordertraversal(postorder, inorder, inorderstart, postorderIndx,posn-1,size,valuetoindexmap);
return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
     int inorderstart=0;
     int inorderend=inorder.size()-1;
     int size=inorder.size();
     int postorderIndx=size-1;
     unordered_map<int,int>valuetoindexmap;
     for(int i=0;i<size;i++){
        valuetoindexmap[inorder[i]]=i;
     }
     return constructbinarytreefrominorderandpostordertraversal(postorder,inorder,inorderstart,postorderIndx,inorderend,size,valuetoindexmap);
    }
};