class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        int V=numCourses;
        // Check if cycle exist in an UNDIRECTED GRAPH
        vector<bool>vis(V,false);

        for(auto &e:prerequisites){
            int u=e[0];
            int v=e[1];

            adj[v].push_back(u);
        }
        // Let's apply kahn's algo with BFS / topologicalSort with DFS 
        queue<int>que;
vector<int>result;
        // prepare a vector of indegree
        vector<int>indegree(V,0);

        for(int i=0;i<V;i++){
            for(int &v:adj[i]){
                    indegree[v]++;
            }
        }

        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                result.push_back(i);
                que.push(i);
            }
        }

        while(!que.empty()){
            int u=que.front();
            que.pop();
            

            for(int &v:adj[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    que.push(v);
                    result.push_back(v);
                } 
            }

        }
                if(result.size() != V) return {};
        // cnt==v -> means topo sort yes and acyclic also yes 

    return result;
    }
};