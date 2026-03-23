class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mpp;
        set<int>st;
        for(auto it:arr){
            mpp[it]++;
        }
        for(auto it=mpp.begin();it!=mpp.end();it++){
            st.insert(it->second);
        }
        if(mpp.size()!=st.size()) return false;
        return true;
    }
};