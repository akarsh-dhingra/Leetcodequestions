class Solution {
public:
/// using hashing one approach will be possible: 
    string decodeMessage(string key, string message) { 
        unordered_map<char,char>mpp;
        // vector<char>hash(26);
        vector<char>seen(26,0);
        // for(int i=0;i<26;i++){
        //     hash[i]=(char)i+97;
        // }
        char alpha = 'a';
   for(char c:key){
    if(c!=' '&&mpp.find(c)==mpp.end()){
        mpp[c]=alpha;
        alpha++;
    }
   }
        string res="";
        for(int i=0;i<message.size();i++){
            if(message[i]==' '){
                res+=' ';
            }
            else res.push_back(mpp[message[i]]);
        }
        return res;
    }
};