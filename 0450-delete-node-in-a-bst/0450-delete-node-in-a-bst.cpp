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
    //     vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int>temp={};
    //     if(root==NULL){
    //         return temp;
    //     }
    //     vector<int>left=inorderTraversal(root->left);
    //     vector<int>right=inorderTraversal(root->right);
    //     temp.insert(temp.end(),left.begin(),left.end());
    //     temp.push_back(root->val);
    //     temp.insert(temp.end(),right.begin(),right.end());
    //     return temp;
    // }
    TreeNode* maxElement(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        TreeNode*temp=root;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Intution:: Search node and then delete it and then link the nodes according to it.
            // inorder traversal of binary tree sa sorted milega 
            // Important tip in lined list and trees start by considering edge cases and then uild from there for super easy and clean codes
        // Algorihm:: I"ll see is it elog to left or rightsubtree the node of the key   
            // Now I can simply do one thing that is elementjoh bhi delete kiya hai uska joh right if exists toh usse place after         previous element's left and iss element ka left wll also be deleted element ka left.
        // sorted mai sa delete and use that sorted to creat tree;
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            // ab delete krunga
            // 4 cases 
            if(root->right==NULL&&root->left==NULL){
                delete root;
                return NULL;
            }
           else if(root->right!=NULL&&root->left==NULL){
                TreeNode*ele=root->right;
                delete root;
                return ele;
            }
           else if(root->right==NULL&&root->left!=NULL){
                TreeNode*ele=root->left;
                delete root;
                return ele;
            }
            else{
                TreeNode*maxele=maxElement(root->left);
                root->val=maxele->val;
                root->left=deleteNode(root->left,maxele->val);
                return root;
            }
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};