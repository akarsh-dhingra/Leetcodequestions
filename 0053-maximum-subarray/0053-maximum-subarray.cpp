class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i]->. 
        int currSum=nums[0];
        int maxiSum=nums[0];
      for(int i=1;i<nums.size();i++){
        currSum=max(currSum+nums[i],nums[i]);
        // dp[i]=max(nums[i]+dp[i-1],nums[i]);
        maxiSum=max(maxiSum,currSum);
      }
      return maxiSum;
    }
};