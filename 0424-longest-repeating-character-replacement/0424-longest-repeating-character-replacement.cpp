class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxlen=0;
        int l=0;
        int hash[26]={0};
        int maxf=0;
        for(int r=0;r<n;r++){
            hash[s[r]-'A']++;
            maxf=max(maxf,hash[s[r]-'A']);
           int changes=(r-l+1)-maxf;
            if(changes>k){
                hash[s[l]-'A']--;
                l++;
            }
            if(changes<=k){
                maxlen=max(maxlen,r-l+1);
            }
        }
        return maxlen;
        }
};