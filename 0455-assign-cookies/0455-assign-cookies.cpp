class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size();// children array
        int n=s.size();
        int l=0;
        int r=0;
        int cnt=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(l<n&&r<m){
            if(g[r]<=s[l]){
                cnt++;
                l++;
                r++;
            }
            else{
                l++;
            }
        }
        return cnt;
    }
};