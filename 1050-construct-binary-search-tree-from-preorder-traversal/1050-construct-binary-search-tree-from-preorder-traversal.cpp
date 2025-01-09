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
TreeNode* constructbinarytreefrompreorderandinordertraversal(vector<int>& preorder, vector<int>& inorder,int inorderstart,int &preorderIndx,int inorderend,int size,unordered_map<int,int>&valuetoindexmap){
if(preorderIndx>=size||inorderstart>inorderend){
    return NULL;
}
// Step 1:
int element=preorder[preorderIndx];
preorderIndx++;
// Step 2:
TreeNode*root=new TreeNode(element);
int posn=valuetoindexmap[element];
root->left=constructbinarytreefrompreorderandinordertraversal(preorder, inorder, inorderstart, preorderIndx,posn-1,size,valuetoindexmap);
root->right=constructbinarytreefrompreorderandinordertraversal(preorder, inorder, posn+1, preorderIndx,inorderend,size,valuetoindexmap);
return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     int inorderstart=0;
     int preorderIndx=0;
     int inorderend=preorder.size()-1;
     int size=preorder.size();
     unordered_map<int,int>valuetoindexmap;
     for(int i=0;i<size;i++){
        valuetoindexmap[inorder[i]]=i;
     }
     return constructbinarytreefrompreorderandinordertraversal(preorder,inorder,inorderstart,preorderIndx,inorderend,size,valuetoindexmap);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>pre;
        pre=preorder;
       sort(preorder.begin(),preorder.end());
       vector<int>inorder;
       for(auto it:preorder){
        inorder.push_back(it);
       }
       return buildTree(pre,inorder);
    }
};