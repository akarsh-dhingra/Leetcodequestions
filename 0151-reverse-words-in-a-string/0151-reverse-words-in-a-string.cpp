class Solution {
public:
    string reverseWords(string s) {
        // reverse the entire string 
        reverse(s.begin(),s.end());
        string ans="";
        if(s==" ")return "";
        int n=s.length();
        for(int i=0;i<s.length();i++){
           string temp="";
            while(i<n && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            if(temp.size()>0){
                reverse(temp.begin(),temp.end());
                ans=ans+" "+temp;
            }
           }
        return ans.substr(1);
    }   
};