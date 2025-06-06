class Solution {
public:
bool checkpalindrome(string&ch,int start,int end){
    // t.c=0(len)
    while(start<end){
        if(ch[start]==ch[end]){
            start++;
            end--;
        }
        else{
            return false;
        }
    }
    return true;
}
    bool validPalindrome(string s) {
        if(checkpalindrome(s,0,s.length())) return true;
        int low=0;
        int high=s.size()-1;
        while(low<=high){
            if(s[low]==s[high]){
                swap(s[low],s[high]);
                low++;
                high--;
            }
            else{
                // s[i]!=s[j]
                // 1 removal allowed
                // check palindrome for remaining string after removal. 
                bool ans1=checkpalindrome(s,low+1,high);
                bool ans2=checkpalindrome(s,low,high-1);
                return ans1||ans2;
            }
        }
        return true;
    }
};