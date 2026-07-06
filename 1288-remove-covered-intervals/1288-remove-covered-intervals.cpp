class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
sort(intervals.begin(), intervals.end(),
[](auto &a, auto &b){
    if(a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
});
for(auto it:intervals) {
    cout<<it[0]<<" "<<it[1]<<endl;
}
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            int c=ans.back()[0];  //2.  
            int d=ans.back()[1];  // 8 
            // c<=a and b<=d
            if(c<=intervals[i][0]&&intervals[i][1]<=d){
                continue;
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
    return ans.size();
    }
};