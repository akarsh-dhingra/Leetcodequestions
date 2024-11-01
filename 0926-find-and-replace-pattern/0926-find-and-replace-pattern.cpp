class Solution {
public:
// this function normalises all the words and patterns into a similar format.
// so that we can compare  
void createmapping(string &str){ // create mapping 
      char start='a';
      char mapping[300]={0};
      
      for(auto ch:str){
         if(mapping[ch]==0){
            mapping[ch]=start;
            start++;
         }
      }
      // update the string 
      for(int i=0;i<str.length();i++){
   char ch=str[i];
   str[i]=mapping[ch];
      }
}
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        // before going on to words
        // Normalize the pattern if it is not abb or any similar kind simply normalize it.
        createmapping(pattern);

        for(string s:words){
            string tempstring=s;
            createmapping(tempstring);
            if(tempstring==pattern){
                ans.push_back(s);
            }
        }
        return ans;
    }
};