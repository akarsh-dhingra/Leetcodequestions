class Solution {
public:
    int solveUsingRec(vector<int>& nums,int i){
        if(i<0) return 0;
        int take=nums[i]+solveUsingRec(nums,i-2);
        int skip=solveUsingRec(nums,i-1);
        return max(take,skip);
    }
    int solveUsingMem(vector<int>& nums,int i,vector<int>&dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+solveUsingRec(nums,i-2);
        int skip=solveUsingRec(nums,i-1);
        return dp[i]=max(take,skip);
    }
    int solveUsingTab(vector<int>& nums){
        int n=nums.size();
        if (n == 1)
            return nums[0];
        vector<int>dp(n,-1);
        

        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int indx=0;
        // We are dividing the problem into two parts
        // one from [0--n-2]
        // two from [1--n-1]
        if (n == 1)
            return nums[0];

        vector<int>first(nums.begin(),nums.end()-1);
        vector<int>second(nums.begin()+1,nums.end());

        return max(solveUsingTab(first),solveUsingTab(second));
    }
};