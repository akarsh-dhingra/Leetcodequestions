class Solution {
public:
    int lengthOfLongestSubstring(string s) {
                   int n=s.length();
                   int maxlen=INT_MIN;
                   int l=0;
                   int r=0;
                   unordered_map<char,int>mpp;
                   if(n==0) return 0;
                    while(r<n){
                        mpp[s[r]]++;
                        while(mpp[s[r]]>1){
                            mpp[s[l]]--;
                            if(mpp[s[l]]==0)mpp.erase(s[l]);
                            l++;
                        }
                        maxlen=max(maxlen,r-l+1);
                        r++;
                    }
        return maxlen;
    }
};