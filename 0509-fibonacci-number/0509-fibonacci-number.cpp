class Solution {
public:
    int solveUsingRec(int n){
        if (n==0 || n==1) return n;
        return solveUsingRec(n-1)+solveUsingRec(n-2);
    }
    // Stepn 2: Pass into function and copy logic 

    int solveUsingMem(int n,vector<int>&dp){
        if (n==0 || n==1) return n;
        // Step 4: If ans already exists then reutrn it.
        if(dp[n]!=-1) return dp[n];
        // Step 3: Return the ans in Dp array
        return dp[n]=solveUsingMem(n-1,dp)+solveUsingMem(n-2,dp);
    }   
    int solveUsingTab(int n){
        // DP pass 
        vector<int>dp(n+1,-1);
        // DP ki state maination 
        dp[0]=0;
        if(n==0) return dp[0];
        dp[1]=1;

        // Then recursion ka reverse
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
    int solveUsingSpacOpt(int n){
        if(n==0) return 0;
        int prev1=0;
        int prev2=1;
        for(int i=2;i<=n;i++){
            int curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
    int fib(int n) {
        // Step 1: Create a Dp array and pass it into the function 
        vector<int>dp(n+1,-1);
        return solveUsingSpacOpt(n); 
    }
};