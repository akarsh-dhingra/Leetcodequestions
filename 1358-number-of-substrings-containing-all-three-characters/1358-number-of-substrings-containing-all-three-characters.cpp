class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        int l=0;
        int r=0;
        map<char,int>mpp;
    int n=s.size();
        while(r<s.size()){
            mpp[s[r]]++;
            while(mpp.size()==3){
                cnt=cnt+(n-r);
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            r++;
        }
        return cnt;
    }
};