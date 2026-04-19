class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            // Let's creata an adjacency matrix or graph first
            vector<vector<pair<int,int>>>adj(n);

            for(auto it:flights){
                int sNode=it[0];
                int eNode=it[1];
                int eWt=it[2];
                adj[sNode].push_back({eNode,eWt});
            }
            queue<pair<int,pair<int,int>>>que;
            que.push({0,{src,0}});
            vector<int>dist(n,INT_MAX);
            dist[src]=0;

            while(!que.empty()){
              auto it=que.front();
              que.pop();
              int stops=it.first;
              int node=it.second.first;
              int cost=it.second.second;

              if(stops>k) continue;  
                for(auto it:adj[node]){
                    int padosi=it.first;
                    int edw=it.second;

                    if(edw+cost<dist[padosi] && stops<=k){
                        dist[padosi]=edw+cost;
                        que.push({stops+1,{padosi,edw+cost}});
                    }
                }
            }

            if(dist[dst]==INT_MAX) return -1;
            return dist[dst];
            
    }
};