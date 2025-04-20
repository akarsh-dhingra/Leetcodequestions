class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
    int n=arr.size();
    int low=0;
    int high=n-1;
    if(n==1){
        return arr[0];
    }
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid==0&&arr[0]!=arr[1]) return arr[0];
        if(mid==n-1&&arr[n-1]!=arr[n-2]) return arr[mid];

        if(arr[mid-1]!=arr[mid]&&arr[mid]!=arr[mid+1]) return arr[mid];

        if(mid%2==0){
        if(arr[mid-1]==arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    else{
        if(arr[mid-1]==arr[mid]){
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