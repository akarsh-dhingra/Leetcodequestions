class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        vector<string>ans;  
        int l=0;
        int r=0;
        int cnt=0;
        string best="";
        int minLen=INT_MAX;
        while(r<n){
            if(s[r]=='1') cnt++;
            while(cnt==k){
                int len=r-l+1;
                string candidate=s.substr(l,len);
                if(candidate.length()<minLen){
                    best=candidate;
                    minLen=candidate.length();
                }
                else if(candidate.length() == minLen && candidate < best){
                    best=candidate;
                }
                if(s[l]=='1') cnt--;
                l++;
            }
            r++;
        }

        return best;
    }
};