class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        
       long long value=0;
       int n=nums.size();
       if(n==1) return 0;
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());

        return 1LL*k*(maxi-mini);
       
    }
};