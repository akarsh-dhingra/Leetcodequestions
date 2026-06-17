class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        sort(firstList.begin(),firstList.end());
        sort(secondList.begin(),secondList.end());
        int n=firstList.size();
        int m=secondList.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int aStart=firstList[i][0];
            int aEnd=firstList[i][1];
            for(int j=0;j<m;j++){
                int bStart=secondList[j][0];
                int bEnd=secondList[j][1];
                

                int start=max(aStart,bStart);
                int end=min(aEnd,bEnd);
                if(start<=end ){
                    ans.push_back({start,end});
                }
            }
        }
        
        return ans;
    }
};