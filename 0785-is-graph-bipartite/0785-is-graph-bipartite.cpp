class Solution {
public:
    bool DFS(vector<int>&color,vector<vector<int>>&adj,int curr, int currColor){
        queue<int>que;
        que.push(curr);
        color[curr]=currColor;

        while(!que.empty()){
            int u=que.front();
            que.pop();
            
            for(int &v:adj[u]){
                if(color[v]==color[u]) return false;

               else if(color[v]==-1){
                    color[v]=1-color[u];
                    que.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            for(auto &v:graph[i] ){
                adj[i].push_back(v);
            }
        }

        // Now I have to check for biparrtite
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!DFS(color,adj,i,1)){
                    return false;
                }
            }
        }
        return true;
    }
};