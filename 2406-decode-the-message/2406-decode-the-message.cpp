class Solution {
public:
/// using hashing one approach will be possible: 
    string decodeMessage(string key, string message) {
        // create mapping 
           char start='a';
           char mapping[128]={0};
           for(auto it : key){
            if(it!=' '&& mapping[it]==0){
            mapping[it]=start;// it hai voh key[0] par hai abhi intially 
            start++;
            }
           }
        // use mapping 
         string ans="";
         for(auto ch:message){
            if(ch==' '){
            ans.push_back(' ');
            }
            else{
                 char decodeChara=mapping[ch];
                 ans.push_back(decodeChara);
            }
         }
         return ans;
    }
};