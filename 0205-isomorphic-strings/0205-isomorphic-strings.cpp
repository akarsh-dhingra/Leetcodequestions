class Solution {
public:
    bool isIsomorphic(string s, string t) {
       vector<bool>tseen(256,0);

       vector<int>hash(256,0);

       for(int i=0;i<s.size();i++){
       if(hash[s[i]]==0&&!tseen[t[i]]){
       hash[s[i]]=t[i];
       tseen[t[i]]=true;
       }   
       }
       string ans="";
       for(int i=0;i<s.size();i++){
ans.push_back(hash[s[i]]);
       }
       if(ans==t) return true;
       else return false;
    }
};