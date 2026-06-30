class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }            
        vector<pair<char,int>>v(mpp.begin(),mpp.end());
        sort(v.begin(),v.end(),[](const auto &a,const auto &b){
            return a.second>b.second;
        });
        string ans="";

        for(auto it:v){
            for(int i=0;i<it.second;i++)
                ans+=it.first;
        }
        return ans;
    
    }
};