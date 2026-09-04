class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int maxi=INT_MIN;
        int miniIndx=100;
        while(r<n){
            maxi=max(nums[l],maxi);
            int mini=INT_MAX;
            for(int i=r;i<n;i++){
                mini=min(mini,nums[i]);
            }
            r++;
            if(maxi-mini<=k){
                miniIndx=min(miniIndx,l);
            }
            l++;
        }
    return miniIndx==100?-1:miniIndx;
    }
};