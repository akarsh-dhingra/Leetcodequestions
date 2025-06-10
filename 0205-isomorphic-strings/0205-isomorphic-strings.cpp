class Solution {
public:
vector<char> createmapping(string&s,string&t){
    vector<bool>seen(256,false);
    vector<char>hash(256,0);
    for(int i=0;i<s.size();i++){
        if(!seen[t[i]]&&hash[s[i]]==0){
            hash[s[i]]=t[i];
            seen[t[i]]=true;
        }
    }
    return hash;
}
    bool isIsomorphic(string s, string t) {
        vector<char>hash=createmapping(s,t);
        string res="";
        for(int i=0;i<s.size();i++){
            res+=hash[s[i]];
        }
        if(res==t) return true;
        else return false;
    }
};