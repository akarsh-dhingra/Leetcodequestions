class Solution {
public:
        vector<int>rank;
    vector<int>parent;

    int find(int x){
        if(x==parent[x]) return x;
        
        return parent[x]=find(parent[x]);
    }

    void unionn(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);

        if(parent_x==parent_y) return ;

        if(rank[parent_x]<rank[parent_y]){
            parent[parent_x]=parent_y;
        }
        else if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
        }
        else{
            parent[parent_y]=parent_x;
            rank[parent_x]++;
        }   
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        parent.resize(n);
        rank.resize(n,1);

        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
        int compCount=n;
        for(auto &v:connections){
            int e1=v[0];
            int e2=v[1];

            if(find(e1)!=find(e2)){
                unionn(e1,e2);
                compCount--;
            }
        }
        return compCount-1;
    }
};