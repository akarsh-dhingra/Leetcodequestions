class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int subArr=0;
        int product=1;
        int n=nums.size();
        if(k<=1) return 0;
        while(j<n){
            product*=nums[j];
            while(product>=k){
                product/=nums[i];
                i++;
            }
            subArr+=(j-i+1);
            j++;
        }
    // since both i and j pointer moved only towards the right and never 
    // moved backward hene there is not a chance even that the T.C: can be 
    // O(n^2) because that's only possible when the pointer will mov
    // backward since that never happened hence the t.c is o(n^2)


        return subArr;
    }
};