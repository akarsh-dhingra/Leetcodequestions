class Solution {
public:
bool checkpalindrome(string k, int start,int end){
  while(start<end){
    if(k[start]==k[end]){
        start++;
        end--;
    }
    else return false;
  }
  return true;
}
    bool validPalindrome(string s) {
        int i=0;
        int j= s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
            i++;
            j--;
            }
            else{
                // s[i]!=s[j]
                // 1 removal allowed
                // check palindrome for string after removal.
                bool ans1=checkpalindrome(s,i+1,j);
                bool ans2=checkpalindrome(s,i,j-1);
                 return ans1 || ans2;
            }
        }
        // agar yahan tk pohoche ho yaahni valid palindrome
        // yahni 0 removals
    // agar palindrome aapka valid hai toh uss particular case mai aap 
    return true;
    }
};