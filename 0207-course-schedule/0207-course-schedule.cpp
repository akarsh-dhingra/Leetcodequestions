class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        int V=numCourses;
        if(prerequisites.size()==0) return true;
        // Check if cycle exist in an UNDIRECTED GRAPH
        vector<bool>vis(V,false);
        for(auto &e:prerequisites){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
        }
        // Let's apply kahn's algo with BFS / topologicalSort with DFS 
        queue<int>que;

        // prepare a vector of indegree
        vector<int>indegree(V,0);

        for(int i=0;i<V;i++){
            for(int &v:adj[i]){
                    indegree[v]++;
            }
        }

        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
int cnt=0;
        while(!que.empty()){
            int u=que.front();
            que.pop();
            cnt++;

            for(int &v:adj[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    que.push(v);
                } 
            }

        }
        // cnt==v -> means topo sort yes and acyclic also yes 
    return cnt==V?true:false; 
    // If false that means topo sort nahi lg skta that means it's cyclice 
    // yahi check krna tha 

    }
};