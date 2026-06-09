class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i]->. 
        int sum=0;
        int maxiSum=INT_MIN;
      for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        maxiSum=max(maxiSum,sum);
        if(sum<0) sum=0;
      }

      return maxiSum;
    }
};