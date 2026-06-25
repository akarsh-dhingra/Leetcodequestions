class Solution {
    public:
    int solveUsingRec(int n){
        if(n==0||n==1) return 1;
        int oneStep=solveUsingRec(n-1);
        int twoStep=solveUsingRec(n-2);
        return oneStep+twoStep;
     }
     int solveUsingMem(vector<int>&dp,int n){
        if(n==0||n==1) return dp[n]=1;
        if(dp[n]!=-1) return dp[n];
        int oneStep=solveUsingMem(dp,n-1);
        int twoStep=solveUsingMem(dp,n-2);
        return dp[n]=oneStep+twoStep;
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
        return solveUsingSpaceOpt(n);
    }
};