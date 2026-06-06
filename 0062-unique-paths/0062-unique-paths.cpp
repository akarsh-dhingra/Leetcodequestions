class Solution {
public:
    int cnt=0;
    int solveUsingRec(int i,int j){
        if(i==0||j==0) return 1;
        if(i<0 || j<0) return 0;

        int up=solveUsingRec(i-1,j);
        int left=solveUsingRec(i,j-1);
        return up+left;
    }
    int solveUsingMem(int i,int j, vector<vector<int>>&dp){
        if(i==0||j==0) return dp[i][j]=1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solveUsingMem(i-1,j,dp);
        int left=solveUsingMem(i,j-1,dp);
        dp[i][j]=up+left;
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        // Move down 
        // Move right 
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solveUsingMem(m-1,n-1,dp);
    }
};