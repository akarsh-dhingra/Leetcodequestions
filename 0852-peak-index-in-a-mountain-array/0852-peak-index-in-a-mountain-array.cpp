class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // 1st edge case:
        long long n=arr.size();
        if(arr[0]>arr[1]) return 0;
        if(arr[n-1]>arr[n-2]) return n-1;
        long long low=1;
        long long high=n-2;

    while(low<=high){
        long long mid=low+(high-low)/2;
        if(arr[mid]>arr[mid-1] &&arr[mid]>arr[mid+1]){
            return mid;
        }                
        else if(arr[mid]<arr[mid+1]){
            low=mid+1;
        }
        else if(arr[mid]<arr[mid-1]) high=mid-1;
    }
return -1;
    }
};