class Solution {
public:
    int find(vector<int>& nums, int k){
                // Whenever we are not sure about shrinking or expanding
        // that is when we think of a different solution

        // no.distinct with <=k - no.distinct with <=k-1

        int l=0;
        int r=0;
        
        unordered_map<int,int>mpp;
        int cnt=0;
        int n=nums.size();
        while(r<n){
            mpp[nums[r]]++;

            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++; 
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return find(nums,k)-find(nums,k-1);
    }
};