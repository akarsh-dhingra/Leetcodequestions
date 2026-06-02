class Solution {
public:
    int maxProfit(vector<int>& prices) {
    //    [7,1,5,3,6,4]
        // Now we've to maximise
        // choose a single day to buy one stock and 
        // different day to sell one 
        // Calculate Profit
        int n=prices.size();
        int maxProfit=0;
        int mini=prices[0];
        for(int i=1;i<n;i++){
            int cost=prices[i]-mini;
            maxProfit=max(maxProfit,cost);
            mini=min(mini,prices[i]);
            }
            return maxProfit;   
        }
};