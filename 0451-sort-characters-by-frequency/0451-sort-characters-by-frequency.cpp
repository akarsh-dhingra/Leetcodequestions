class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char c:s){
            freq[c]++;
        }
        // frequency stored!
// data copied from map into vector
        vector<pair<char,int>>freqVec(freq.begin(),freq.end());
        // sorted as per frequecy
     sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });
    string res;
    for(auto it:freqVec){
        res.append(it.second,it.first);
    }

        // int freqmax=INT_MIN;
        // for(auto it:mpp){
        //     freqmax=max(freqmax,it.second);
        // }
        // vector<int>t(mpp.size());
        // for(auto it:t){
        //     t.push_back()
        // }
        return res;
    }
};