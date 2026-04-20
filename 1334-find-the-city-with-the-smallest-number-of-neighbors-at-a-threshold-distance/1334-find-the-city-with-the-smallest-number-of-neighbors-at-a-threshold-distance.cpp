class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
      vector<vector<int>>adj(n,vector<int>(n,INT_MAX));

      for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];

        adj[u][v]=wt;
        adj[v][u]=wt;
      }  
    
    for(int k=0;k<n;k++) adj[k][k]=0;

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k]<INT_MAX && adj[k][j]<INT_MAX){
                            adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);    
            }       
        }
    }
}
int cntCity=n;
int cityNo=-1;
for(int city=0;city<n;city++){
    int cnt=0;
    for(int adjCity=0;adjCity<n;adjCity++){
        if(adj[city][adjCity]<=distanceThreshold)
            cnt++;
    }
    if(cnt<=cntCity){
        cntCity=cnt;
        cityNo=city;
    }
}
return cityNo;
    }
};