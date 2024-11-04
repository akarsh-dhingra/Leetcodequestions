class Solution {
public:
    bool isAnagram(string s, string t) {
if(s.size()!=t.size()) return false;
int hashans[26]={0};
for(int i=0;i<s.size();i++){
    hashans[s[i]-'a']++;
}
for(int i=0;i<t.size();i++){
    hashans[t[i]-'a']--;
}
for(int i=0;i<26;i++){
      if(hashans[i]!=0){
        return false;
      }
}
return true;
    }
};