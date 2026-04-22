class DisjointSet{
public:
vector<int>rank,parent,size;

DisjointSet(int n){
    rank.resize(n+1,0);
    // Declaring as n+1 will work both for one based and 0 based indexing 
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n =accounts.size();
        unordered_map<string,int>mpp;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mpp.find(accounts[i][j])==mpp.end()){
                    mpp[accounts[i][j]]=i;
                }
                else{
                    ds.unionBySize(i,mpp[accounts[i][j]]);
                }
            }
        }

        vector<string>mergedMail[n];

        for(auto it:mpp){
            string mail=it.first;
            int node=ds.findParent(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};