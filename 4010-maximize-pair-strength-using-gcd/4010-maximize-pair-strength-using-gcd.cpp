class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        long long maxStrength=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long gcdd=pow(gcd(nums[i],nums[j]),2);
                long long strength=(long long)nums[i]*nums[j];
                strength=strength/gcdd;
                maxStrength=max(maxStrength,strength);
            }
        }
        return maxStrength;
    }
};