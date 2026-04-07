class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>que;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    que.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
         int deltaRow[]={-1,0,1,0};
         int deltaCol[]={0,1,0,-1};

         while(!que.empty()){
            int r=que.front().first.first;
            int c=que.front().first.second;
            int d=que.front().second;
            dist[r][c]=d;
            que.pop();
            for(int i=0;i<4;i++){
                int nRow=r+deltaRow[i];
                int nCol=c+deltaCol[i];

        if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && vis[nRow][nCol]==0){
                    vis[nRow][nCol]=1;
                    que.push({{nRow,nCol},d+1});
                }
            }
         }
        return dist;
    }
};