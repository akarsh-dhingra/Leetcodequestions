class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(), points.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });           
        int initPosition=points[0][1];
        int arrowCnt=1;
        for(int i=1;i<n;i++){
            if(initPosition>=points[i][0]){
                continue;
            }
            else{
                initPosition=points[i][1];
                arrowCnt++;
            }
        }
        return arrowCnt;

    }
};