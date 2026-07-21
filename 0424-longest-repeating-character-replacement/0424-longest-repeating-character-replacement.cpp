class Solution {
public:
    int characterReplacement(string s, int k) {
           int n=s.size();
           int l=0;
           int r=0;
           int maxlen=0;
           int maxF=0;
           vector<int>hash(26,0);

            while(r<n){
                hash[s[r]-'A']++;
                maxF=max(maxF,hash[s[r]-'A']);
                if((r-l+1)-maxF>k){
                    hash[s[l]-'A']--;   
                    l++;
                }
                if((r-l+1)-maxF<=k){
                    maxlen=max(maxlen,r-l+1);
                }
                r++;
            }
// Return the length of the longest substring containing 
// the same letter you can get after performing the above operations.
           return maxlen;
    }
};