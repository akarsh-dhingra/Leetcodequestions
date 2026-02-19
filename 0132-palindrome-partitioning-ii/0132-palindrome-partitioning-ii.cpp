class Solution {
public:
    bool isPalinDrome(string s,int i,int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }

    int solveUsingTab(string s, int n){
        vector<long long>dp(n+1,0);
        dp[n]=0;
            vector<vector<bool>> pal(n, vector<bool>(n, false));

    // Build palindrome table
    for(int gap = 0; gap < n; gap++){
        for(int i = 0, j = gap; j < n; i++, j++){
            if(gap == 0) pal[i][j] = true;
            else if(gap == 1) pal[i][j] = (s[i] == s[j]);
            else pal[i][j] = (s[i] == s[j] && pal[i+1][j-1]);
        }
    }
        for(int i=n-1;i>=0;i--){
            int minCost=INT_MAX;
            for(int j=i;j<n;j++){
            if(pal[i][j]){
                int cost=1+dp[j+1];
                minCost=min(minCost,cost);
            }
        }
        dp[i]=minCost;
        }
        return dp[0]-1;
    }
    int minCut(string s) {
        int n=s.length();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<long long>dp(n,0);
        return solveUsingTab(s,n);
    }
};