/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* ,Node* >mpp;
    void DFS(Node* node,Node*cloneNode){
        for(auto it:node->neighbors){
            if(mpp.find(it)==mpp.end()){
                Node*cloned=new Node(it->val);
                mpp[it]=cloned;
                cloneNode->neighbors.push_back(cloned);
                DFS(it,cloned);
            }
            else{
                cloneNode->neighbors.push_back(mpp[it]);
            }
        }
    }
    
    void BFS(Node*node){
        queue<Node*>que;
        que.push(node);

        while(!que.empty()){
            Node*init=que.front();
            Node*cloneNode=mpp[init];
            que.pop();
            for(auto it:init->neighbors){
                if(mpp.find(it)==mpp.end()){
                    Node*cloned=new Node(it->val);
                    mpp[it]=cloned;
                    que.push(it);
                    cloneNode->neighbors.push_back(cloned);
                }
                else{
                    cloneNode->neighbors.push_back(mpp[it]);
                }
            }
        }
    }

    Node* cloneGraph(Node* node) {  
        if(node==NULL) return node;
        Node*clone_node=new Node(node->val);
        mpp[node]=clone_node;
        BFS(node);
        return clone_node;
    }
};