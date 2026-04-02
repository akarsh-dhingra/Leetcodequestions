class Solution {
public:
    void DFS(vector<vector<int>>&adj,vector<bool>&vis,int u){
        vis[u]=true;
        for(int &v:adj[u]){
            if(!vis[v]){
                DFS(adj,vis,v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int N=isConnected[0].size();
        vector<vector<int>>adj(N);
        vector<bool>vis(N,false);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                DFS(adj,vis,i);
                count++;
            }
        }
        return count;
    }
};