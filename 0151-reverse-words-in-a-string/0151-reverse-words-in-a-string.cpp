class Solution {
public:
    string reverseWords(string s) {
        // the sky is blue
        // blue is sky the 
        // eulb si yks eht

        reverse(s.begin(),s.end());
        string ans="";
        int n=s.length();
        for(int i=0;i<s.length();i++){
            // We will extract individual words
              string word="";
              while(i<n && s[i]!=' '){
                    word+=s[i];
                    i++;
              }
              reverse(word.begin(),word.end());
              if(word.length()>0) ans+=" "+word;
        }
        return ans.substr(1);
    }   
};