class Solution {
public:
    double timeTaketoEat(vector<int>& piles,int t){
        double time=0;
        for(int x:piles){
            time+=ceil((double)x/t);
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(timeTaketoEat(piles,mid)<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};