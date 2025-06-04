class Solution {
public:
    string removeDuplicates(string s) {
        // step 1:choosing any adjacent and two equal letters indx and indx+1
        // step 2: delete those and use this string to repeat step 1
        // step 3: return
        // edge case if no adjacent duplicates
        // stack sa 
        // string ko built krte hai from scratch -> Pattern
        // find 
        int len=s.length();
        string ans;
        int indx=0;
        while(indx < s.length()){
           // same
           // ans ka rightmost char delete krdenge and string s ka curr char
           if(ans.length()>0&&ans[ans.length()-1]==s[indx]){
            ans.pop_back();
           }
          else {
            ans.push_back(s[indx]);
          }
          indx++;
        }
        return ans;
    }
};