class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
vector<vector<int>> ans(m, vector<int>(n, 0));
        queue<pair<int,int>>que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==m-1||i==0||j==0||j==n-1)&&grid[i][j]==1){ 
                    ans[i][j]=1;
                    que.push({i,j});
                    }
            }
        }
vector<int>delRow={-1,0,1,0};
vector<int>delCol={0,1,0,-1};
        while(!que.empty()){
            pair<int,int>curr=que.front();
            int currRow=curr.first;
            int currCol=curr.second;

            que.pop();

            for(int i=0;i<4;i++){
                int nRow=currRow+delRow[i];
                int nCol=currCol+delCol[i];

                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && grid[nRow][nCol]==1 && ans[nRow][nCol]==0 ){
                    que.push({nRow,nCol});
                    ans[nRow][nCol]=1;
                }
            }
        }
                  int cnt=0;
            for(int i=0; i<m;i++){
                for(int j=0;j<n;j++){
                    if(ans[i][j]==0 && grid[i][j]==1) cnt++;
                }
            }
return cnt;
    }
};