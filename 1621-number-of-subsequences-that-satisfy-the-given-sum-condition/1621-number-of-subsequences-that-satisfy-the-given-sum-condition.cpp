class Solution {
public:
    int numSubseq(vector<int>& nums, int target){
        // vector of pairs
        int mod= 1e9+7;
        int count=0;
        int l=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int r=n-1;
        vector<int>power(n,1);
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%mod;
        }
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                int len=r-l;
                count=(count+power[len])%mod;
                //  result = (result + power[right - left]) % MOD;
                l++;
            }
            else{
                r--;
            }
        }
        return count;
    }
};