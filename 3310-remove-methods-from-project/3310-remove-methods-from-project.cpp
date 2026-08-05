class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // k travel BFS 
        // Mark suspicious nodes and update indegree of nodes 
        // suspicious && indegree!=0  return graph else remove that node from result.
        
        vector<vector<int>>adj(n);
        vector<int>suspicious(n,false);
        vector<int>indegree(n,0);

        for(auto it:invocations){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            indegree[v]++;
        }
        

        queue<int>que;
        que.push(k);
        suspicious[k]=true;

        while(!que.empty()){
            int curr=que.front();
            que.pop();

            for(int &ngbr:adj[curr]){
                    indegree[ngbr]--;
                    if(!suspicious[ngbr]){
                        suspicious[ngbr]=true;
                        que.push(ngbr);
                    }
            }
        }

    vector<int>result;
    bool currSeen=false;

    for(int i=0;i<n;i++){
        if(suspicious[i] && indegree[i]>0){
            currSeen=true;
            break;
        }
        if(!suspicious[i]){
            result.push_back(i);
        }
    }

    if(currSeen){
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=i;
        }
        return ans;
    }
    return result;
    }
};