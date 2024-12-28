class Solution {
public:
    string minWindow(string s, string t) {
         if (s.empty() || t.empty()) return "";
        int minlen=INT_MAX;
        int n=s.size();
        int m=t.size();
        int sIndx=-1;
        int r=0;
        int l=0;
        int hash[256]={0};
             int cnt=0;
            for(int j=0;j<m;j++){
                hash[t[j]]++;
            }
      while(r<n){
        if(hash[s[r]]>0){
            cnt+=1;
        }
        hash[s[r]]--;
        r++;
        while(cnt==m){
            if(r-l<minlen){
                minlen=r-l;
                sIndx=l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0){
                cnt-=1;
            }
            l++;
        }
      }
    return sIndx == -1 ? "" : s.substr(sIndx, minlen);
    }
};