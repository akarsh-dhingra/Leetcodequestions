class Solution {
public:
    int solveUsingRec(int n,vector<int>& coins, int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0) return INT_MAX;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int ans=solveUsingRec(n,coins,amount-coins[i]);
            if(ans!=INT_MAX){
                mini=min(mini,1+ans);
            }
        }
        return mini;
    }
    int solveUsingMem(vector<int>&dp,vector<int>& coins, int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0) return INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=solveUsingMem(dp,coins,amount-coins[i]);
            if(ans!=INT_MAX){
                mini=min(mini,1+ans);
            }
        }
        return dp[amount]=mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,-1);
        int ans= solveUsingMem(dp,coins,amount);
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};