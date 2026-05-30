class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();

        int m=s2.length();
        sort(s1.begin(),s1.end());
        for(int i=0;i<=m-n;i++){
            string substring =s2.substr(i,n);
            
            sort(begin(substring),end(substring));
            if(s1==substring){
                return true;
            }

        }
        return false;
    }
};