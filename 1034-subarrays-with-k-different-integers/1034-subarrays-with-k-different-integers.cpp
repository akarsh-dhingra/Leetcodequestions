class Solution {
public:
int numSubarraysWithSumlesserthangoal(vector<int>& nums, int k){
    if(k<0) return 0;
    int n=nums.size();
    map<int,int>mpp;
    int cnt=0;
    int l=0;
    for(int r=0;r<n;r++){
        mpp[nums[r]]++;
        while(mpp.size()>k){
           if(mpp.size()>k){
                    mpp[nums[l]]--;
                    if(mpp[nums[l]]==0){
                        mpp.erase(nums[l]);
                    }
                    l++;
                }
        }
        cnt+=(r-l+1);
    }
return cnt;
 }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return numSubarraysWithSumlesserthangoal(nums,k)-numSubarraysWithSumlesserthangoal(nums,k-1) ;
    }
};