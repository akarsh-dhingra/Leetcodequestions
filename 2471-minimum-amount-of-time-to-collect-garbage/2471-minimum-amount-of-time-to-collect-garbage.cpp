class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickM=0;
        int pickG=0;
        int pickP=0;

        // three trucks paper truck,garbage truck and  metal truck.
        int travelP=0;
        int travelM=0;
        int travelG=0;

        int lastP=0;
        int lastM=0;
        int lastG=0;
// inn teeno ka use krkr mai travel time nikal lunga because merko pta hai 
// plastic khata krne ka liye klha tk jaan hai and so on.
        // calculate pick and travel time

       int i=0;
        for(auto str:garbage){
            string curr=str;
           for(char c:curr){
            if(c=='P'){
                pickP+=1;
                lastP=i;
            }
            else if(c=='G'){
                pickG+=1;
                lastG=i;
            }
            else {
                pickM+=1;
                lastM=i;
            }
           }
           i++;
        }
        for(int i=0;i<lastM;i++){
            travelM+=travel[i];
        }
        for(int i=0;i<lastG;i++){
            travelG+=travel[i];
        }
        for(int i=0;i<lastP;i++){
        travelP+=travel[i];
        }
int ans=(pickP+travelP)+(pickM+travelM)+(pickG+travelG);
        return ans;
    }
};