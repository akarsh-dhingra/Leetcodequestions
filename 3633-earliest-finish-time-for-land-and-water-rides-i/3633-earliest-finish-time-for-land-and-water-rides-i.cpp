class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int duration=0;
        int minFinishTimeLand=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            int finishTime=landStartTime[i]+landDuration[i];
            minFinishTimeLand=min(finishTime,minFinishTimeLand);
        }
        int minFinishTimeWater=INT_MAX;
        int land_water=INT_MAX;
        int water_land=INT_MAX;
        for(int j=0;j<waterStartTime.size();j++){
            int finishTime=waterStartTime[j]+waterDuration[j];
            minFinishTimeWater=min(finishTime,minFinishTimeWater);
        }
        for(int j=0;j<waterStartTime.size();j++){
            land_water=min(land_water,max(waterStartTime[j],minFinishTimeLand)+waterDuration[j]);
        }
        for(int i=0;i<landStartTime.size();i++){
        water_land=min(water_land,max(landStartTime[i],minFinishTimeWater)+landDuration[i]);
        }
        return min(land_water,water_land);
    }   
};