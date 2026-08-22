class Solution {
public:
    int solveUsingRec(vector<int>&prices,int indx,bool buy,vector<vector<int>>&dp){
    if(indx==prices.size()){
        return 0;
    }
    if(dp[indx][buy]!=-1) return dp[indx][buy];
    int profit=0;
    if(buy){
        profit=max(-prices[indx]+solveUsingRec(prices,indx+1,0,dp),solveUsingRec(prices,indx+1,1,dp));
    }
    else{
        profit=max(prices[indx]+solveUsingRec(prices,indx+1,1,dp),solveUsingRec(prices,indx+1,0,dp));
    }
    return dp[indx][buy]= profit;
}

    int maxProfit(vector<int>& prices) {
        int indx=0;
	    int buy=1;
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int buysandsell=solveUsingRec(prices,indx,buy,dp);
        
        return buysandsell;

    }
};