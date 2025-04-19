class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int prev=(mid+n-1)%n;
            int next=(mid+1)%n;
            if(nums[mid]<=nums[prev]&&nums[mid]<=nums[next]) return nums[mid];
            else if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return -1;
    }
};