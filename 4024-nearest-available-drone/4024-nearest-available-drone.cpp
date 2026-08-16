class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int dx=target[0];
        int dy=target[1];

        // abs(x-dx)+abs(y-dy)<= rangei
        int minIndx=-1;
        int minDist=INT_MAX;
        for(int i=0;i<drones.size();i++){
            int x1=drones[i][0];
            int y1=drones[i][1];
            int rangeI=drones[i][2];
            int dist=abs(x1-dx)+abs(y1-dy);
            if(dist<=rangeI && dist<minDist ){
                minIndx=i;
                minDist=dist;
            }
        }
        return minIndx;
    }
};