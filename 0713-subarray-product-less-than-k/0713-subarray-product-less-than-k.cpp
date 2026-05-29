class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        int product=1;
        int subArr=0;
        if(k<=1) return 0;
        while(j<n){
            // every time j++ j-i+1 will get added
            product*=nums[j];
            while(product>=k){
                product/=nums[i];
                i++;
            }
            subArr+=(j-i+1);
            j++;
        }
        return subArr;
    }
};