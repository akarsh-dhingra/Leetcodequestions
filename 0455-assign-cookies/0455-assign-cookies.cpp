class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
            int l=0;
            int r=0;
            sort(s.begin(),s.end());
            sort(g.begin(),g.end());
            int n=g.size();
            int m=s.size();
        // s child
        // g greed 
            while(l<m && r<n){
                if(g[r]<=s[l]){
                    r++;
                }
                l++;
            }
            return r;
    }
};