class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty()||t.empty()) return "";
        int n=s.size();
        int m=t.size();
        int minlen=INT_MAX;
        int sIndx=-1;
        int cnt=0;
        int hash[256]={0};
        int l=0;
        int r=0;
        for(int i=0;i<m;i++){
            hash[t[i]]++;
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
        return sIndx==-1?"":s.substr(sIndx,minlen);
    }
};