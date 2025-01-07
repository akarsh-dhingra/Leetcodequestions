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
// vector<vector<int>> levelordertraversal(TreeNode* a){
// vector<vector<int>>temp;

// if(a==NULL){
//     return temp;
// }
// queue<TreeNode*>q;
// q.push(a);
// while(!q.empty()){
//     int levelsize=q.size();
//     vector<int>level;
//     for(int i=0;i<levelsize;i++){
//         TreeNode*currele=q.front();
//         q.pop(); // iss step mai we are creating nodes of each curr eleme
       
//         level.push_back(currele->val);
//         if(currele->left) q.push(currele->left);
//         if(currele->right) q.push(currele->right);
//     }
//     temp.push_back(level);
// }
// return temp;
// }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Levelordertraversal's vector of Tree p== LevelorderTraversal's of q
        // can I comment that yeas both are same tree 
    //     vector<vector<int>>first=levelordertraversal(p);
    //     vector<vector<int>>second=levelordertraversal(q); 
    //    if(equal(first.begin(),first.end(),second.begin())){
    //     return true;
    //    }
    //     else return false;
    // }
    if(p==NULL&&q==NULL){
        return true;
    }
    if(p==NULL||q==NULL){
        return false;
    }
    // if(p->val!=q->val){
    //     return false;
    // }
    if(p->val==q->val){
       bool a= isSameTree(p->left,q->left);
       bool b= isSameTree(p->right,q->right);
        return a&b;
    }
    else return false;
    }
};