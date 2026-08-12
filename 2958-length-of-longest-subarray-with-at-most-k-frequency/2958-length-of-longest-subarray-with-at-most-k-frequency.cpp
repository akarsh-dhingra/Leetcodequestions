class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
            // Brute force -> Take unordered_map check for frequency while traversing for 
            // every subarray the moment kuch backchodi theen break out for that starting indx
            int maxlen=INT_MIN;
            int l=0;
            int r=0;
            int n=nums.size();
            unordered_map<int,int>mpp;
            while(r<n){
                mpp[nums[r]]++;
                while(mpp[nums[r]]>k){
                    mpp[nums[l]]--;
                    if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                    l++;
                }
                 maxlen=max(maxlen,r-l+1);
                 r++;
            }
            return maxlen;
    }
};