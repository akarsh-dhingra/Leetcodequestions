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
    TreeNode* createMapping(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&nodetoParent,int start){
        queue<TreeNode*>que;
        que.push(root);
        TreeNode* target=NULL;
        nodetoParent[root]=NULL;
        while(!que.empty()){
            TreeNode* front=que.front();
            que.pop();

            if(front->val==start){
                target=front;
            }
            if(front->left){
                nodetoParent[front->left]=front;
                que.push(front->left);
            }
            if(front->right){
                nodetoParent[front->right]=front;
                que.push(front->right);
            }
        }
        return target;
    }
    void burnTree(unordered_map<TreeNode*,TreeNode*>&nodetoParent,int start,int &ans, TreeNode* targetNode){
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>que;
        que.push(targetNode);

        visited[targetNode]=true;
        while(!que.empty()){
            int size=que.size();
            bool flag=0;
            for(int i=0;i<size;i++){
                TreeNode*front=que.front();
                que.pop();
                
                if(front->left && !visited[front->left]){
                    flag=1;
                    que.push(front->left);
                    visited[front->left]=true;
                }
                 if(front->right && !visited[front->right]){
                    flag=1;
                    que.push(front->right);
                    visited[front->right]=true;
                }
                if(nodetoParent[front]&& !visited[nodetoParent[front]]){
                    flag=1;
                    que.push(nodetoParent[front]);
                    visited[nodetoParent[front]]=true;
                }

            }
            if(flag==1) ans++;
        }
        return;
    }
    int amountOfTime(TreeNode* root, int start) {
        // Step 1: Create Mapping and finding Target Node
        // Step 2: Bunring the tree from the target.
        int ans=0;
        unordered_map<TreeNode*,TreeNode*>nodetoParent;
        TreeNode* targetNode= createMapping(root,nodetoParent,start);
        burnTree(nodetoParent,start,ans,targetNode);
        return ans;
    }
};