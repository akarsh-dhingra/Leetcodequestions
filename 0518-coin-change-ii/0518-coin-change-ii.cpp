class Solution {
public:
 int subsetsum(vector<int>&coins,int amount,int n){
 vector<vector<double>>t(n + 1, vector<double>(amount + 1, 0));
  for(int i = 0; i < n + 1; i++) {
        t[i][0] = 1; // Only base case needed
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<amount+1;j++){
            if(coins[i-1]<=j){
                t[i][j]=t[i-1][j]+t[i][j-coins[i-1]];
            }
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][amount];
 }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int noofways=subsetsum(coins,amount,n);
        return noofways;
    }
};