class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // saare parts krna 
        int maxProfit=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]-mini>maxProfit){
                maxProfit=prices[i]-mini;
            }
            else{
                mini=min(mini,prices[i]);
            }
        }
        return maxProfit;   
    }
};