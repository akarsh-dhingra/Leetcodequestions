class Solution {
public:
    bool DFS(vector<int>&color,vector<vector<int>>&adj,int curr, int currColor){
        color[curr]=currColor;

        for(int &v:adj[curr]){
            if(color[v]==color[curr]){
                return false;
            }
            if(color[v]==-1) {
                int colorofV=1-currColor;
                if(DFS(color,adj,v,colorofV)==false) return false;
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