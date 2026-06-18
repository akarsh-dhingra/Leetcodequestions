class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int startI=intervals[0][0];
        int endI=intervals[0][1];
        int cnt=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<endI){
                cnt++;
                endI=min(intervals[i][1],endI);
            }
            else{
                endI=intervals[i][1];
            }
        }
        return cnt;
    }
};