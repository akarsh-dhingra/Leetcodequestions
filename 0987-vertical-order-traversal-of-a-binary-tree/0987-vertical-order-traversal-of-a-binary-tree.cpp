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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
            //  Creating a map firstly 
            map<int,map<int,vector<int>>>nodes;
            // Hd , LEVEL, VECTOR OF NODES
            queue<pair<TreeNode*,pair<int,int>>>que;
            //  
            vector<vector<int>>ans;

            if(root==NULL) return ans;
            que.push(make_pair(root,make_pair(0,0)));

            while(!que.empty()){
                pair<TreeNode*,pair<int,int>>temp=que.front();
                que.pop();

                TreeNode* frontNode=temp.first;
                int hd=temp.second.first;
                int lvl=temp.second.second;

                nodes[hd][lvl].push_back(frontNode->val);

                if(frontNode->left){
                    que.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
                }
                if(frontNode->right){
                    que.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
                }
            }
//             for(auto &col : nodes){

//     vector<int> vertical;

//     for(auto &level : col.second){

//         vertical.insert(vertical.end(),
//                         level.second.begin(),
//                         level.second.end());
//     }

//     ans.push_back(vertical);
// }
            for(auto it:nodes){
                vector<int> vertical;
                for(auto j:it.second){
                    sort(j.second.begin(), j.second.end());

                      for(int x : j.second)
                            vertical.push_back(x);
                }
                ans.push_back(vertical);
            }
            return ans;
    }
};