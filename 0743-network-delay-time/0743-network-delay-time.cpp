class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>>adj(n+1);

    for(auto &it:times){
        int u=it[0];
        int v=it[1];
        int wt=it[2];

        adj[u].push_back({v,wt});
    }

    set<pair<int,int>>st;
    st.insert({0,k}); // dist,src
    vector<int>dis(n+1,INT_MAX);
    dis[k]=0;

    while(!st.empty()){
        auto it=*(st.begin());
        int node=it.second;
        int wt=it.first;

        st.erase(it);

        for(auto &it:adj[node]){
            int neigh=it.first;
            int dist=it.second;

            if(dist+wt<dis[neigh]){
                if(dis[neigh]!=INT_MAX){
                    st.erase({dis[neigh],neigh});
                }
                st.insert({dist+wt,neigh});
                dis[neigh]=dist+wt;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(dis[i]==INT_MAX) return -1;
        ans=max(ans,dis[i]);
    }
    return ans;
    }
};