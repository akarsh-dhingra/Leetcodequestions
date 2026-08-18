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
    int solveUsingTab(vector<int>& cost,int n){
            vector<int>dp(n+2,0);
            for(int i=n-1;i>=0;i--){
                dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
            }
            return min(dp[0],dp[1]);
    }
    int solveUsingOpto(vector<int>&cost,int n){
        int aage1=0;
        int aage2=0;
        for(int i=n-1;i>=0;i--){
            int curr=cost[i]+min(aage1,aage2);
            aage2=aage1;
            aage1=curr;
        }
        return min(aage1,aage2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return solveUsingOpto(cost,n);
    }
};