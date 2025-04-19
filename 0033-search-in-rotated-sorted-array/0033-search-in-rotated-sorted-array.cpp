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
            if(nums[mid]<=nums[prev]&&nums[mid]<=nums[next]) return mid;
            else if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return -1;
    }
    int bs(vector<int>& nums, int low,int high,int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) high=mid-1;
            else{
                low=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
       int n=nums.size();
       int low=0;
       int high=n-1;
       int minelindx=findMin(nums);
       int a=bs(nums,low,minelindx-1,target);
       int b=bs(nums,minelindx,high,target);
       if(a!=-1){
        return a;
       }
       else if(b!=-1){
        return b;
       }
       else{
        return -1;
       }
    }
};