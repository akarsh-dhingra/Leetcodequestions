class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>result;
        int n=intervals.size();
        int i=0;
        if(intervals.size()==0){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<int>tempinterval=intervals[0];
        for(auto it:intervals){
            if(it[0]<=tempinterval[1]){
                tempinterval[1]=max(it[1],tempinterval[1]);
            }
            else{
                result.push_back(tempinterval);
                tempinterval=it;
            }
            }
            result.push_back(tempinterval);
       return result;
    }
};