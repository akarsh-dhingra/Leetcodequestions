class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int n=nums.size();
        if(n==1) return 0; 
    // arr[i-1]<=arr[i]>=arr[i+1]
    while(low<=high){
      int mid=low+(high-low)/2;
      if(nums[low]>nums[low+1]) return low;
      if(nums[high]>nums[high-1]) return high;
      if(nums[mid-1]<=nums[mid] && nums[mid]>=nums[mid+1]){
        return mid;
      }
      else{
        if(nums[mid-1]<=nums[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
      }
    }
    return -1;
    }
};