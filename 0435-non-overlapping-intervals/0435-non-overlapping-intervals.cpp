class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        int end=intervals[0][1];
        int cnt=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=end){
                end=intervals[i][1];
            }
            else{
                cnt++;
                end=min(intervals[i][1],end);
            }
        }
        return cnt;

    }
};