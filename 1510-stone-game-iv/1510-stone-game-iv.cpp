class Solution {
public:
    bool solveUsingRecForAlic(int n){
        if(n==0) return false;

        for(int k=1;k*k<=n;k++){
            if(solveUsingRecForAlic(n-k*k)==false) return true;
        }
        return false;
    }
    int solveUsingMem(int n,vector<bool>&dp){
        if(n==0) return false;
        if(dp[n]!=false) return dp[n];
        for(int k=1;k*k<=n;k++){
            if(solveUsingMem(n-k*k,dp)==false) return dp[n]= true;
        }
        return dp[n]=false;
    }
    bool winnerSquareGame(int n) {
        vector<bool>dp(n+1,false);
        return solveUsingMem(n,dp);
    }
};