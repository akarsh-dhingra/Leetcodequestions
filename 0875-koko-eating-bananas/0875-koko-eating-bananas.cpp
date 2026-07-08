class Solution {
public: 
    double hoursTaken(int k,vector<int>& piles){
        double ghante=0;
        for(int i=0;i<piles.size();i++){
                ghante+=ceil((double)piles[i]/k);
        }
        return ghante;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // k=1 to max number of bananas 
        int  low=1;
        int  high=*max_element(piles.begin(),piles.end());
        int  ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(hoursTaken(mid,piles)<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                // aur tez kha agr 30 par bat nahi bn rhi bnan rjhi toh aur tez kha 
                // tera misconception 
                low=mid+1;
            }
        }
        return ans;
    }
};