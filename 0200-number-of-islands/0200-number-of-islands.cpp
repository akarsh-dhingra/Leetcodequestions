class Solution {
public:
    void bfss(int row, int col, vector<vector<char>>& grid,vector<vector<bool>>&vis){
        vis[row][col]=1;
        queue<pair<int,int>>que;
        que.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!que.empty()){
            int row1=que.front().first;
            int col1=que.front().second;
            que.pop();

            // Now i have to traverse in its neighbours now how to get tot it's negihbours

            for(int i=0;i<4;i++ ){
               int nRow = row1 + delRow[i];
               int nCol = col1 + delCol[i];
                        
                    if(nRow>=0&&nRow<n&&nCol>=0&&nCol<m
                    &&grid[nRow][nCol]=='1'&&!vis[nRow][nCol]){
                            vis[nRow][nCol]=true;
                            que.push({nRow,nCol});
                    }
                }
            }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        // I have to first conver the char into 
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int cnt=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col]&& grid[row][col]=='1'){
                    bfss(row,col,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};