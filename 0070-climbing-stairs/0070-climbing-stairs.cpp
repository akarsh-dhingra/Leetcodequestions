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
    int solveUsingTab(int n){
        vector<int>dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int solveUsingSpaceOpt(int n){
        int prev1=1;
        int prev2=1;
        for(int i=2;i<=n;i++){
            int curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
    int climbStairs(int n) {
        // 1. Create a dp arrya of size n
        vector<int>dp(n+1,-1);
        return solveUsingSpaceOpt(n);
    }
};