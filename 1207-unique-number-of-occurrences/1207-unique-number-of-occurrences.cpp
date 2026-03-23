class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mpp;
        set<int>st;
        for(auto it:arr){
            mpp[it]++;
        }
        for(auto it=mpp.begin();it!=mpp.end();it++){
            int freq=it->second;
            if(st.find(freq)!=st.end()){
                return false;
            }          
            st.insert(freq);
        }
        return true;
    }
};