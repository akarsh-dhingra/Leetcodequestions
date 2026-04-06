class Solution {
public:
    void solveBfs(vector<vector<bool>>&vis,vector<vector<char>>& grid,int n,int m,int curRow,int curCol){
        queue<pair<int,int>>que;
        que.push({curRow,curCol});
        vis[curRow][curCol]=true;

        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        while(!que.empty()){
            int topR=que.front().first;
            int topC=que.front().second;

            que.pop();
            for(int i=0;i<4;i++){
                int nRow=topR+deltaRow[i];
                int nCol=topC+deltaCol[i];
        if(nRow>=0&&nRow<n&&nCol>=0&&nCol<m && vis[nRow][nCol]==false && grid[nRow][nCol]=='1' ){
            que.push({nRow,nCol});
            vis[nRow][nCol]=true;
        }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int islands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false && grid[i][j]=='1'){
                    islands++;
                    solveBfs(vis,grid,n,m,i,j);
                }
            }
        }
        return islands;
    }
};