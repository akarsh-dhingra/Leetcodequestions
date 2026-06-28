class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int start=0;
        int maxLen=1;
        // for 1 length vaale substring 

        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }

        // for 2 length vaale substring 

        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                // Logic behind this is agr 3 vaalo mai kuch nahi aata 
                // toh this will be the answer 
                start=i;
                maxLen=2;
            }
        }

        for(int len=3;len<=n;len++){
            
            for(int i=0;i<=n-len;i++){

                int j=i+len-1;

                if(s[i]==s[j] && dp[i+1][j-1]==true){
                    dp[i][j]=true;
                    if(len>maxLen){
                        maxLen=len;
                        start=i;
                    }
                }
            }
        }
    return s.substr(start,maxLen);
    }
};