class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<int>ans(n,0);
        ans[0]=sum-nums[0];
        int leftSum=0;
        for(int i=1;i<n;i++){
            leftSum+=nums[i-1];
            int rightSum=sum-leftSum-nums[i];
            ans[i]=abs(leftSum-rightSum);
        }
        return ans;
    }
};