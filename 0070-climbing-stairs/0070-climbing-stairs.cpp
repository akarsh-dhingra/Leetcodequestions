class Solution {
    public:
    int solveUsingRec(int n){
        if(n==0||n==1) return 1;
        int oneStep=solveUsingRec(n-1);
        int twoStep=solveUsingRec(n-2);
        return oneStep+twoStep;
     }
     int solveUsingMem(vector<int>&dp,int n){
       if(n==0||n==1) return 1;
       if(dp[n]!=-1) return dp[n];
        int oneStep=solveUsingMem(dp,n-1);
        int twoStep=solveUsingMem(dp,n-2);
        return dp[n]=oneStep+twoStep;
     }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solveUsingMem(dp,n);
    }
};