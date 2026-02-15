class Solution {
public:
    int solveUsingRec(vector<int>& nums,int i, int j){
        if(i>j) return 0;
        int maxCost=INT_MIN;
    for(int k=i;k<=j;k++){
int cost=nums[i-1]*nums[k]*nums[j+1]+solveUsingRec(nums,i,k-1)+solveUsingRec(nums,k+1,j);
            maxCost=max(maxCost,cost);
        }
        return maxCost;
    }
int solveUsingMem(vector<int>& nums,int i, int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return 0;
        int maxCost=INT_MIN;
    for(int k=i;k<=j;k++){
int cost=nums[i-1]*nums[k]*nums[j+1]+solveUsingRec(nums,i,k-1)+solveUsingRec(nums,k+1,j);
            maxCost=max(maxCost,cost);
        }
        dp[i][j]=maxCost;
        return dp[i][j];
    }   
    int solveUsingTab(vector<int>& nums){
        int n=nums.size()-2;
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int maxCost=INT_MIN;
                for(int k=i;k<=j;k++){
                int cost=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                maxCost=max(maxCost,cost);
                 }
                 dp[i][j]=maxCost;
            }
        }
        return dp[1][n];
    } 
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        nums.push_back(1);
      return solveUsingTab(nums);  
    }
};