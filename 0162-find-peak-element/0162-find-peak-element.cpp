class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        // [1,2]
        // [1,2,3,4,5,6]
        int ans=0;
        for(int i=1;i<=n-2;i++){
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1]){
                 ans=i;
            }
        }
        bool flag=true;
        for(int i=0;i<=n-2;i++){
            if(nums[i]>nums[i+1]){
                flag=false;
                break;
            }
        }
        if(flag==true) return n-1;
        else return ans;
    }
};