class Solution {
public:
    int solveUsingRec(int n){
        if (n==0 || n==1) return n;
        return solveUsingRec(n-1)+solveUsingRec(n-2);
    }
    int solveUsingMem(int n,vector<int>&dp){
        if (n==0 || n==1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solveUsingMem(n-1,dp)+solveUsingMem(n-2,dp);
    }   
    int fib(int n) {
        // Step 1: Create a Dp array and pass it into the function 
        vector<int>dp(n+1,-1);
        return solveUsingMem(n,dp); 
    }
};