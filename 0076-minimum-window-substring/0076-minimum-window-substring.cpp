class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        for(auto ch:t){
            mpp[ch]++;
        }
        int n=s.size();
        
        int sIndx=-1;
        long long minLen=INT_MAX;
        int l=0;
        int r=0;
        long long cnt=0;
        while(r<n){
            if(mpp[s[r]]>0) cnt+=1;
            mpp[s[r]]--;
            while(cnt==t.size()){
                if(minLen>r-l+1){
                    sIndx=l;
                    minLen=r-l+1;
                }
                mpp[s[l]]++; // coz reInserting that's why ++
                if(mpp[s[l]]>0) cnt-=1;
                l++;
            }
            r++;
        }
        if(sIndx==-1) return "";
        return s.substr(sIndx,minLen);
    }
};