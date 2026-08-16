class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        // r=arrivalTime[j] % period if r<lights[i] maza aagya 0 period 
        // How long the vehicle waits??
        // we want to minimise the maximum waiting time
        int maxGreen=*max_element(lights.begin(),lights.end());
        int ans=0;
        for(int x:arrivalTime){
            int r=x%period;
            int minWait;
            if(r<maxGreen){
                minWait=0;
            }
            else minWait=period-r;
            ans=max(ans,minWait);
        }
        return ans;
    }
};