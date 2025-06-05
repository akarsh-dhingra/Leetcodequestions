class Solution {
public:
    string frequencySort(string s) {
       // frequency of letter
       vector<int>hash(256,0);
       for(int i=0;i<s.size();i++){
        hash[s[i]]++;
        }
    vector<pair<char, int>> freq;
    for (int i = 0; i < 256; i++) {
        if (hash[i]) freq.push_back({(char)i, hash[i]});
    }
    sort(freq.begin(), freq.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    string res;
    for (auto &p : freq)
        res += string(p.second, p.first);

    return res;
    }
};