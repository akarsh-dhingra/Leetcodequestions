class DisjointSet{

public:
vector<int>rank,parent,size;
DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1,-1);
    size.resize(n+1,1);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
}
int findParent(int node){
    if(parent[node]==node) return node;
    return parent[node]=findParent(parent[node]);
}
void unionByRank(int u, int v){
int u_parent=findParent(u);
int v_parent=findParent(v);

if(v_parent==u_parent) return;

if(rank[u_parent]<rank[v_parent]){
    parent[u_parent]=v_parent;
}
else if(rank[u_parent]>rank[v_parent]){
    parent[v_parent]=u_parent;
}
else{
    parent[u_parent]=v_parent;
    rank[v_parent]++;
}
}

void unionBySize(int u, int v){
int u_parent=findParent(u);
int v_parent=findParent(v);

if(u_parent==v_parent) return;

if(size[u_parent]<size[v_parent]){
       parent[u_parent]=v_parent;
       size[v_parent]+=size[u_parent];
}
else{
    parent[v_parent]=u_parent;
    size[u_parent]+=size[v_parent];
}
}

};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet ds(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }
        int cnt=0;

        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cnt++;
        } 
    return cnt;
    }
};
