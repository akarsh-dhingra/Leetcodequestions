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
TreeNode*makenodetoparentMappingandfindtargetnode(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parentmap ,int start){
    // LEVEL ORDER TRAVERSAL
    queue<TreeNode*>q;
    q.push(root);
    TreeNode*tarele=0;
    parentmap[root]=0;
    while(!q.empty()){
        TreeNode*currele=q.front();
        q.pop();
        if(currele->val==start){
            tarele=currele;
        }
        if(currele->right){
            q.push(currele->right);
            parentmap[currele->right]=currele;
        }
        if(currele->left){
            q.push(currele->left);
            parentmap[currele->left]=currele;
        }
    }
    return tarele;
}
int burnThetree(TreeNode* tarele,unordered_map<TreeNode*,TreeNode*> &parentmap){
    unordered_map<TreeNode*,bool>isburnt;// visited or not
     queue<TreeNode*>q;// currently set on fire nodes
     int T=0;
     q.push(tarele); // targetnode tu burn hogyi hai 
     isburnt[tarele]=1;
     while(!q.empty()){
        int currsize=q.size();
        bool isfirespread=false;
        for(int i=0;i<currsize;i++){
            TreeNode* front=q.front();
            q.pop();
            // left part mai aag spread hogyi hai 
            if(front->left&&!isburnt[front->left]){
                q.push(front->left);
                isburnt[front->left]=1;
                isfirespread=1;
            }
            // right part mai aag spread hgoyi hai 
            if(front->right&&!isburnt[front->right]){
                q.push(front->right);
                isburnt[front->right]=1;
                isfirespread=1;
            }
            // parentpart mai aag ka spread hona
            if(!isburnt[parentmap[front]]&&parentmap[front]){
                q.push(parentmap[front]);
                isburnt[parentmap[front]]=1;
                isfirespread=1;
            }
        }
        if(isfirespread) ++T;
     }
     return T;
}
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parentmap;// Node->its parent pointers
        // Node*targetNode=new TreeNode() yeh naya ele bna dega yeh voh node nahi dhundega jahan sa hume kaam start krna hai jalana ka 
        TreeNode*targetNode=makenodetoparentMappingandfindtargetnode(root,parentmap,start);
        return burnThetree(targetNode,parentmap);
    }

};