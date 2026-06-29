class Solution {
public:
    string reverseWords(string s) {
        // reverse the entire string 
        reverse(s.begin(),s.end());
        string ans="";
        if(s==" ")return "";
        int n=s.length();
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
           else if(temp.size()>0){
                reverse(temp.begin(),temp.end());
                ans=ans+" "+temp;
                temp="";
            }
           }
           if(temp!=""){
            reverse(temp.begin(),temp.end());
            ans=ans+" "+temp;
           }
        return ans.substr(1);
    }   
};