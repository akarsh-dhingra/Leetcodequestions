class Solution {
public:
bool checkpalindrome(string t){
    int n=t.length();
    int low=0;
    int high=n-1;
    while(low<high){
        if(t[low]==t[high]){
            low++;
            high--;
        }
        else return false;
    }
    return true;
}
int printallsubstrings(string s){
    int len=s.length();
    int count=0;
   for(int i=0;i<len;i++){
    for(int j=1;j<=len-i;j++){
        if(checkpalindrome(s.substr(i,j))==true){
            count++;
        }
    }
   }
   return count;
}
    int countSubstrings(string s) {
        // no. of substrings->done
        // check palindrome 
        // count++
        // return 
        int ans=printallsubstrings(s);
        return ans;
    }
};