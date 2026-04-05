class Solution {
public:
    void dfss(vector<vector<int>>&ans,vector<vector<int>>&image,int sr,int sc,int color,int iniColor){
        ans[sr][sc]=color;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int n=ans.size();
        int m=ans[0].size();
        for(int i=0;i<4;i++){
            int nRow=sr+delRow[i];
            int nCol=sc+delCol[i];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m&& image[nRow][nCol]==iniColor&& ans[nRow][nCol]!=color){
                    dfss(ans,image,nRow,nCol,color,iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor=image[sr][sc];
        vector<vector<int>>ans=image;
        dfss(ans,image,sr,sc,color,iniColor);
        return ans;
    }
};