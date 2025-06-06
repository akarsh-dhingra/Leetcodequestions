class Solution {
public:
bool ispalindrome(string&t, int low,int high){
    while(low<=high){
        if(t[low]!=t[high]){
            return false;
        }
        low++;
        high--;
    }
    return true;
}
    string longestPalindrome(string s) {
        string ans="";
        int maxlen=INT_MIN;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(ispalindrome(s,i,j)){
                    string subst=s.substr(i,j-i+1); // using this line before if will increase no. of innecessary operations due to which TLE occurs.
                    ans=subst.size()>ans.size()?subst:ans;
                }
            }
        }
        return ans;
    }
};