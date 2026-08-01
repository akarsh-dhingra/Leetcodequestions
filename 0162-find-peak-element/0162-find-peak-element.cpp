class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        // [1,2]
        // [1,2,3,4,5,6]
        int ans=0;
        for(int i=1;i<=n-2;i++){
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1]){
                return ans=i;
            }
        }
        vector<int>temp=nums;

        sort(temp.begin(),temp.end());
        if(temp==nums) return n-1;
        else return ans;
    }
};