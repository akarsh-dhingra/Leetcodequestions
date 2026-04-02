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
    // Now we will take a queue 
    queue<int>que;
    // We will create an indegree array
    vector<int>indegree(V,0);
    
    for(int i=0;i<V;i++){
        for(int &v:adj[i]){
            indegree[v]++;
        }
    }
    // Now pushing in the onew where indegree[i]=0
    
    for(int i=0;i<V;i++){
        if(indegree[i]==0) que.push(i);
    }
    int cnt=0;
    vector<int>result;
    
    while(!que.empty()){
        int u=que.front();
        cnt++;
        que.pop();
        result.push_back(u);
        
        for(int &v:adj[u]){
            indegree[v]--;
            
            if(indegree[v]==0) que.push(v);
        }
        
    }
    return cnt==V;

    }
};