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
    bool equationsPossible(vector<string>& equations) {
            parent.resize(26);
            rank.resize(26,1);

            for(int i=0;i<26;i++){
                parent[i]=i;
            }
            for(string &s:equations){
               if(s[1]=='=') {
                    unionn(s[0]-'a',s[3]-'a');  //a==b 0th and 3rd indx vaale ko we'll do reunion
               }
            }
            for(string &s:equations){
                if(s[1]=='!'){
                   if(find(s[0]-'a')==find(s[3]-'a')){
                        return false;
                    } 
                }
            }
            return true;
    }
};