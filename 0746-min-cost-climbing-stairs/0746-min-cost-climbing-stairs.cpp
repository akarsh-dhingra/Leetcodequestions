class Solution {
public:
    int solveUsingRec(vector<int>& cost,int start,int n){
        if(start>=n){
            return 0;
        }
        int firstWays=cost[start]+solveUsingRec(cost,start+1,n);
        int secondWays=0;
      if(start+1<n){
         secondWays=cost[start+1]+solveUsingRec(cost,start+2,n);
        }
    return min(firstWays,secondWays);
    }
    int solveUsingMem(vector<int>& cost,int start,int n,vector<int>&dp){
        if(start>=n){
            return 0;
        }
        if(dp[start]!=-1) return dp[start];
        int firstWay=cost[start]+solveUsingMem(cost,start+1,n,dp);
        int secondWay=cost[start]+solveUsingMem(cost,start+2,n,dp);
        return dp[start]=min(firstWay,secondWay);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(solveUsingMem(cost,0,n,dp),solveUsingMem(cost,1,n,dp));
    }
};