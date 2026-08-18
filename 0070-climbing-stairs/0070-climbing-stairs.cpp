class Solution {
public:
    int solveUsingRec(int n){
        if(n==1|| n==0) return 1;
        int firstWay=solveUsingRec(n-1);
        int secondWay=solveUsingRec(n-2);
        return firstWay+secondWay;
    }
    int solveUsingMem(int n,vector<int>&dp){
        if(n==1|| n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int firstWay=solveUsingMem(n-1,dp);
        int secondWay=solveUsingMem(n-2,dp);
        return dp[n]=firstWay+secondWay;
    }
    int climbStairs(int n) {
        // 1. Create a dp arrya of size n
        vector<int>dp(n+1,-1);
        return solveUsingMem(n,dp);
    }
};