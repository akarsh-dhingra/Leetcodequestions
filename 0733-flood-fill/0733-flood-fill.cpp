class Solution {
public:
vector<int>delRow={-1,0,1,0};
vector<int>delCol={0,1,0,-1};
void DFS(vector<vector<int>>& image,int oldColor,int color,int sr, int sc,vector<vector<int>>&ans,int n,int m){
    ans[sr][sc]=color;

    for(int i=0;i<4;i++){
        int newRow=sr+delRow[i];
        int newCol=sc+delCol[i];

        if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && 
            image[newRow][newCol]==oldColor && 
            ans[newRow][newCol]!=color
         ){
            ans[newRow][newCol]=color;
            DFS(image,oldColor,color,newRow,newCol,ans,n,m);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor=image[sr][sc];
        if(oldColor==color) return image;
        vector<vector<int>>ans=image;
        int n=image.size();
        int m=image[0].size();
        DFS(image,oldColor,color,sr,sc,ans,n,m);
        return ans;
    }
};