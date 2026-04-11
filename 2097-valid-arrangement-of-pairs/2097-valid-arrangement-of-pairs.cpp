
class Solution {
public:

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Let's create an adjacency list

        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>indegree,outdegree;
        for(int i=0;i<pairs.size();i++){
            int a=pairs[i][0];
            int b=pairs[i][1];

            adj[a].push_back(b);
            outdegree[a]++;
            indegree[b]++;
        }
        int startNode=pairs[0][0];

        for(auto &it:adj){
            int node=it.first;
            if(outdegree[node]-indegree[node]==1){
                startNode=node;
                break;
            }
        }
        vector<int>EulerPath;
        stack<int>st;
        st.push(startNode);

        while(!st.empty()){
            int topNode=st.top();

            if(!adj[topNode].empty()){
                int nghbour=adj[topNode].back();
                adj[topNode].pop_back();
                st.push(nghbour);
            }   
            else{
                EulerPath.push_back(topNode);
                st.pop();
            }
        }
        reverse(begin(EulerPath),end(EulerPath));
        vector<vector<int>>result;

        for(int i = 0; i < EulerPath.size() - 1; i++){
    result.push_back({EulerPath[i], EulerPath[i+1]});        
    }
        return result;
    }
};