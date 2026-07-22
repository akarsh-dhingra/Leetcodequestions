class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int n=s.length();
            int maxlen=INT_MIN;
            if(n==0) return 0;
            for(int i=0;i<n;i++){
                unordered_map<char,int>mpp;
                for(int j=i;j<n;j++){
                    if(mpp.find(s[j])!=mpp.end()) break;
                    mpp[s[j]]++;
                    maxlen=max(maxlen,j-i+1);
                }
            }
        return maxlen;
    }
};