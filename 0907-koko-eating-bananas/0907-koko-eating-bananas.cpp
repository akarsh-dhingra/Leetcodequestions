class Solution {
public:
int maximumel(vector<int>& piles){
    int maxi=INT_MIN;
    for(int i=0;i<piles.size();i++){
        if(piles[i]>maxi){
            maxi=piles[i];
        }
    }
    return maxi;
}
double hours(vector<int>& piles,int hours){
   double totalhours=0;
    for(int i=0;i<piles.size();i++){
        totalhours+=ceil((double)piles[i]/(double)hours);
    }
    return totalhours;
}
int minEatingSpeed(vector<int>& piles, int h) {
        // INTUTION:
        //  We are given an array of piles of bananas, the ith pile has piles[i]
        //  Guards have gone and will come in h hours
        int low=1;
        int high=maximumel(piles);
        while(low<=high){
            int mid=low+(high-low)/2;
            double timetaken=hours(piles,mid);
            if(timetaken<=h){
              high=mid-1;
            }
            else{
            low=mid+1;
            }
        }
        return low;
    }
};