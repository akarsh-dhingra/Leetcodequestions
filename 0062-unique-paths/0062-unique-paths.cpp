class Solution {
public:
    
    int solveUsingRec(int i,int j){
        if(i==0&&j==0) return 1;
        if(i<0 || j<0) return 0;
        int top=solveUsingRec(i-1,j);
        int left=solveUsingRec(i,j-1);

        return top+left;
    }
    int solveUsingTab(int m,int n){
        vector<vector<long long>>dp(m+1,vector<long long >(n+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++) dp[0][i]=1;
        for(int i=1;i<=m;i++) dp[i][0]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        return solveUsingTab(m,n);
    }
};