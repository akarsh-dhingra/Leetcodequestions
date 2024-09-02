class Solution {
public:
int lower_bound(vector<int>&nums, int target, int n){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low +(high-low)/2;
        if(nums[mid]>=target){
             ans=mid;
             high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int upper_bound(vector<int>&nums, int target,int n){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low +(high-low)/2;
        if(nums[mid]>target){
             ans=mid;
             high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
     int n= nums.size();
     int ub=upper_bound(nums,target,n);
     int lb=lower_bound(nums,target,n);
     if(lb==n || nums[lb]!=target){
        return {-1,-1};
     }
     else {
        return {lb,ub-1};
     }
}
};