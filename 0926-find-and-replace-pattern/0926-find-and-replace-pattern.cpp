class Solution {
public:
string createMapping(string &s){
unordered_map<char,char>mpp;
char alpha='a';
for(char c:s){
    if(c!=' '&&mpp.find(c)==mpp.end()){
        mpp[c]=alpha;
        alpha++;
    }
}
for(int i=0;i<s.length();i++){
    char curr=s[i];
    s[i]=mpp[curr];
}
return s;
}
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            string curr=words[i];
           if(createMapping(curr)==createMapping(pattern)){
            ans.push_back(words[i]);
            }
        }
        return ans;
    }
};