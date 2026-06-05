class Solution {
public:
    int solveUsingRec(int n){
        if(n==0 || n==1) return n;

        return solveUsingRec(n-1)+solveUsingRec(n-2);
    }
    int solveUsingMem(int n,vector<int>&dp){
         if(n==0 || n==1) return dp[n]= n;

         if(dp[n]!=-1) return dp[n];
        // step 2: Store the ans in the dp array and return it 
        return dp[n]= solveUsingRec(n-1)+solveUsingRec(n-2);
    }
    int solveUsingTab(int n){
        // Create a dp array in the fucntion
        vector<int>dp(n+1,-1);

        // Analyse the base case and update dp array accordingly
        dp[0]=0;
        if(n==0) return 0;
        dp[1]=1;
        // Reverse the param range and update the arry accordingly 
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int fib(int n) {
        // Step1 : Create a DP array and pass it into the function

        vector<int>dp(n+1,-1);
        return solveUsingTab(n);
    }
};