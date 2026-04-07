class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Apply BFS+ flood Fill

        int n=grid.size();
        int m=grid[0].size();

        // Create a visited arr
        vector<vector<int>>vis(n,vector<int>(m,0));

        // Create a queue becuase it's bfs
        queue<pair<pair<int,int>,int>>que;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    que.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }

        // Now move forward
        int tMax=0;
        int deltaRow[]={-1,0,1,0};
         int deltaCol[]={0,1,0,-1};

        while(!que.empty()){
            int r=que.front().first.first;
            int c=que.front().first.second;
            int t=que.front().second;
            que.pop();
            tMax=max(tMax,t);

            for(int i=0;i<4;i++){
                int nRow=r+deltaRow[i];
                int nCol=c+deltaCol[i];

if(nRow>=0&& nCol>=0&& nRow<n && nCol<m&& vis[nRow][nCol]!=2&&grid[nRow][nCol]==1){
                    vis[nRow][nCol]=2;
                    que.push({{nRow,nCol},t+1});
                }
            }

        }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(vis[i][j]!=2 && grid[i][j]==1) return -1;
        return tMax;
    }
};