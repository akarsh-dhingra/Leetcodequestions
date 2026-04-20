class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
// Dijsktarta
// stops=(src,dest);
// In standard dijsktara my approach was that I used to think 
// in terms of {d,node} but here I"ll think yk in terms of {d,n,stops}
//  I cannot apply dijsktara algo here because yk I may end up 
//  for that matter taking a smaller dist but that may come at a tradeoff of more number of stops which will violate my condition given in the problem 
// hence my criteria for judgement is not primarilyy 
// dist but the stops as well
    vector<vector<pair<int,int>>>adj(n);
    for(auto it:flights){
        adj[it[0]].push_back({it[1],it[2]});
    }
    queue<pair<int,pair<int,int>>>que;
    que.push({0,{src,0}});
    vector<int>dist(n,INT_MAX);
    dist[src]=0;

    while(!que.empty()){
        auto it=que.front();
        int stops=it.first;
        int node=it.second.first;
        int dis=it.second.second;

        que.pop();
        if(stops>k) continue;
            for(auto it:adj[node]){
                int padosi=it.first;
                int edw=it.second;

                if(dis+edw<dist[padosi] && stops<=k ){
                        dist[padosi]=edw+dis;
                        que.push({stops+1,{padosi,edw+dis}});
                }
            }
        }

    if(dist[dst]==INT_MAX) return INT_MAX;
    return dist[dst];

    }
};