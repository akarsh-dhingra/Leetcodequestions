class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        // Brute force that comes 
        vector<int>leftSum(n+1,0);
        for(int i=1;i<=n;i++){
            leftSum[i]=nums[i-1]+leftSum[i-1];
        }
        // 0 10 4+10 14+8  22+3
        vector<int>rightSum(n+1,0);
        for(int i=n-1;i>=0;i--){
            rightSum[i]=rightSum[i+1]+nums[i];
        }
        //     25 15 11 3 0 
        vector<int>ans(n,0);
        for(int i=0;i<n;i++ ){
            ans[i]=abs(rightSum[i]-leftSum[i+1]);
        }
        return ans;
    }
};