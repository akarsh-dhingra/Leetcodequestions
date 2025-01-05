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
    TreeNode* constructreefrominandpreordertraversal(vector<int>& preorder, vector<int>& inorder,int size,unordered_map<int, int>&valueToIndexMap,int &preorderIndx, int inorderStart,int inorderend){
        if(preorderIndx>=size||inorderStart>inorderend){
            return NULL;
        }
        int element=preorder[preorderIndx];
        preorderIndx++;
        TreeNode*root= new TreeNode(element);
           int elementpos= valueToIndexMap[element];
        root->left=constructreefrominandpreordertraversal(preorder,inorder,size,valueToIndexMap,preorderIndx,inorderStart,elementpos-1);
        root->right=constructreefrominandpreordertraversal(preorder,inorder,size,valueToIndexMap,preorderIndx,elementpos+1,inorderend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size=preorder.size();
        int preorderIndx=0;
        int inorderStart=0;
        int inorderend=size-1;
    unordered_map<int, int> valueToIndexMap;
    for (int i = 0; i < size; i++){
        valueToIndexMap[inorder[i]] = i;
    }
        return constructreefrominandpreordertraversal(preorder,inorder,size,valueToIndexMap,preorderIndx,inorderStart,inorderend);
    }
//     TreeNode* constructTreeFromInAndPreOrder(vector<int>& preorder, vector<int>& inorder, 
//                                          int size, int& preorderIndex, 
//                                          int inorderStart, int inorderEnd, 
//                                          unordered_map<int, int>& valueToIndexMap) {
//     if (preorderIndex >= size || inorderStart > inorderEnd) {
//         return NULL;
//     }

//     // Get the current root element and move the preorder index forward
//     int element = preorder[preorderIndex];
//     preorderIndex++:
//     TreeNode* root = new TreeNode(element);

//     // Get the position of the element in the inorder traversal using the map
//     int elementPos = valueToIndexMap[element];

//     // Recursive calls for left and right subtrees
//     root->left = constructTreeFromInAndPreOrder(preorder, inorder, size, preorderIndex, inorderStart, elementPos - 1, valueToIndexMap);
//     root->right = constructTreeFromInAndPreOrder(preorder, inorder, size, preorderIndex, elementPos + 1, inorderEnd, valueToIndexMap);

//     return root;
// }

// TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//     int size = preorder.size();
//     int preorderIndex = 0;
//     int inorderStart = 0;
//     int inorderEnd = size - 1;

//     // Create a map for the inorder traversal to quickly find element positions
//     unordered_map<int, int> valueToIndexMap;
//     for (int i = 0; i < size; i++) {
//         valueToIndexMap[inorder[i]] = i;
//     }

//     // Call the recursive function
//     return constructTreeFromInAndPreOrder(preorder, inorder, size, preorderIndex, inorderStart, inorderEnd, valueToIndexMap);
// }
};