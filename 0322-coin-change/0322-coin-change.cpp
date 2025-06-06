class Solution {
public:
int unbounded(vector<int>& coins,int amount, int n){
    vector<vector<unsigned long long>>t(n+1,vector<unsigned long long>(amount+1,0));
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < amount + 1; j++) {
            if (j == 0) t[i][j] = 0;
            else if (i == 0) t[i][j] = INT_MAX - 1;
        }
    }
        for(int j=1;j<amount+1;j++){
            if(j%coins[0]==0) t[1][j]=j/coins[0];
            else t[1][j]=INT_MAX-1;
        }
    for(int i=2;i<n+1;i++){
        for(int j=1;j<amount+1;j++){
            if(coins[i-1]<=j){
                t[i][j]=min(t[i-1][j],t[i][j-coins[i-1]]+1);
            }
            else t[i][j]=t[i-1][j];
        }
    }
  return t[n][amount] == INT_MAX - 1 ? -1 : t[n][amount];
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int mincoins=unbounded(coins,amount,n);
        return mincoins;
    }
};