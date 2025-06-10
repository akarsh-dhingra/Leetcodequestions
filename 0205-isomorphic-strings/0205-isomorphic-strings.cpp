class Solution {
public:
vector<char> createmapping(string&s,string&t){
    vector<char>hash(256,0);// mapping unordered map could also be used.
    vector<bool>istcharsmapped(256,false); // characters are already mapped this character has al
    // been mapped previously

    for(int i=0;i<s.size();i++){
        if(!istcharsmapped[t[i]]&&hash[s[i]]==0){
            hash[s[i]]=t[i];
            istcharsmapped[t[i]]=true;
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