class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // picking times
        int pickP=0; // picking plastic time.
        int pickM=0; // picking metal time.
        int pickG=0; // picking glass time.
        // travelling times
        int travelP=0; // travelling plastic time.
        int travelM=0; // travelling metal time.
        int travelG=0; // travelling glass time.
        // any truck will go till that particular indx jahan tak usse uska item mil rha hai.
        int lastP=0;
        int lastG=0;
        int lastM=0;

        // calculate pick time and travel time
        for(int i=0;i<garbage.size();i++){
            string curr=garbage[i];
            for(int j=0;j<curr.size();j++){
                char ch=curr[j];
                if(ch=='P'){
                 pickP+=1;
                 lastP=i;
                }
                else if(ch=='G'){
               pickG+=1;
               lastG=i;
                }
                else{
                 pickM+=1;
                 lastM=i;
                }
            }
        }
        
        // calculate travelling times
        for(int i=0;i<lastP;i++){
            travelP+=travel[i];
        }
        for(int i=0;i<lastG;i++){
            travelG+=travel[i];
        }
        for(int i=0;i<lastM;i++){
            travelM+=travel[i];
        }

        int ans=(pickP+travelP)+(pickM+travelM)+(pickG+travelG);
        return ans;
    }
};