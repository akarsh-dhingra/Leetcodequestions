class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // every substring's map maintain krna hai 
        int n=s.length();
        int maxLen=INT_MIN;
        if(n==0) return 0;
        int l=0;
        int r=0;
        unordered_map<int,int>mpp;
        while(r<n){
            mpp[s[r]]++;
            while(mpp[s[r]]>1){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};