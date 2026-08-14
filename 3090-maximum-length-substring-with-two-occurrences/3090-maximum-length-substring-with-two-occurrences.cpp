class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0;
        int r=0;
        unordered_map<int,int>mpp;
        int n=s.size();
        int maxlen=INT_MIN;
        while(r<n){
            mpp[s[r]]++;
            while(mpp[s[r]]>2){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};