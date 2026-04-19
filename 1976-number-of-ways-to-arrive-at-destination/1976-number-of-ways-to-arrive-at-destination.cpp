class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
priority_queue<pair<long long,int>, 
               vector<pair<long long,int>>, 
               greater<pair<long long,int>>> pq;        
               vector<long long>dist(n,1e18);
               vector<int>ways(n,0);
long long mod = 1e9 + 7;        
dist[0]=0;
        pq.push({0,0});
        ways[0]=1;

        while(!pq.empty()){
            long long dis=pq.top().first;
            int node=pq.top().second;

            pq.pop();
            for(auto it:adj[node]){
                int neigh=it.first;
                int edw=it.second;
                // That means i am coming here for the very first time 
                // so that means current ways =1
                if(dis+edw<dist[neigh]){
                    dist[neigh]=dis+edw;
                    pq.push({dis+edw,neigh});
                    ways[neigh]=ways[node];
                }
                else if(dis+edw==dist[neigh]){
                    ways[neigh]=(ways[node]+ways[neigh])%mod;
                }
            }

        }

        return ways[n-1]%mod;
    }
};