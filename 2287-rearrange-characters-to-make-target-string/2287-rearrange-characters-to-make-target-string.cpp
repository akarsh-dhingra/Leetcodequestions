class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int>available;
        unordered_map<char,int>required;

        for(auto it:s){
            available[it]++;
        }

        for(auto it:target){
            required[it]++;
        }
    int ans=INT_MAX;
        for(auto &[ch,freq]:required){
            ans=min(ans,available[ch]/required[ch]);
        }
        return ans;
    }
};