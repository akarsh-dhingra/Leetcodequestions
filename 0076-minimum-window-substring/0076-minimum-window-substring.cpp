class Solution {
public:
    string minWindow(string s, string t) {
        // generate all the substrings and compare their freuqnncies 
        // against t 
        int n=s.length();
        long long m=t.size();
        long long sIndx=-1;
        long long minLen=INT_MAX;
          vector<int>hash(256,0);
             for(auto ch:t){
                hash[ch]++;
            }
        int l=0;
        int r=0;
        int cnt=0;
        while(r<s.size()){
            if(hash[s[r]]>0) cnt=cnt+1;
            hash[s[r]]--;

            while(cnt==m){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    sIndx=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt-=1;
                l++;
            }
        r++;
        }
        if(sIndx == -1)return "";
        return s.substr(sIndx,minLen);
    }
};