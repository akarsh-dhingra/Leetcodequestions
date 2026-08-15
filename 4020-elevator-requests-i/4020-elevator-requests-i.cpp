class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int currPosn=0;
        int time=requests[0];
        if(requests[0]!=0) currPosn=requests[0];
        for(int i=1;i<requests.size();i++){
            if(currPosn==requests[i]) continue;
            else {
                currPosn=requests[i];
                time+=abs(requests[i]-requests[i-1]);
            }
        }
        return time;
    }
};