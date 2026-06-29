class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        //o(nlogn)
        int n=strs.size();
        string a=strs[0];
        string b=strs[n-1];
        int x=a.size();
        int y=b.size();
        int i=0;
        int j=0;
        while(i<x && j<y){
            if(a[i]!=b[j]){
                return a.substr(0,j);
            }
            i++;
            j++;
        }
        return a;
    }
};