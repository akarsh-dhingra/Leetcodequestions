class Solution {
public:
    bool isAnagram(string s, string t) {
            // if at the end hash table is empty 
            // that means both are anagrams of each other

            vector<int>hash(26,0);

            for(int i=0;i<s.size();i++){
                hash[s[i]-'a']++;
            }
            for(int i=0;i<t.size();i++){
                hash[t[i]-'a']--;
            }

            for(auto it:hash){
                if(it!=0) return false;
            }
            return true;
    }
};