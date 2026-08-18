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
    int solveUsingTab(vector<int>& coins, int amount ){
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        if(dp[amount]==INT_MAX) return -1;
        else return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,-1);
        int ans= solveUsingTab(coins,amount);
        return ans;
    }
};