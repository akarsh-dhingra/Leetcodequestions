class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int initProfit=0;
        int mini=prices[0];
        // If I buy of a particular day then I will sell it on ith day
        for(int i=1;i<n;i++){
            int diff=prices[i]-mini;  // because I will always buy on the mini day
            initProfit=max(initProfit,diff);
            mini=min(prices[i],mini);
        }
        return initProfit;
    }
};