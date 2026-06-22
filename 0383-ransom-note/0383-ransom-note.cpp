class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>available;
        unordered_map<char,int>required;
        for(auto it:magazine){
            available[it]++;
        }
        for(auto it:ransomNote){
            required[it]++;
        }

        int mini=INT_MAX;
        for(auto &[ch,freq]:required){
            mini=min(mini,available[ch]/required[ch]);
        }
        cout<<mini<<endl;
        return mini==INT_MAX||mini==0?false:true;
    }
};