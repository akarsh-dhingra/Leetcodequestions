class Solution {
public:
     long long noOfStuds(vector<int> &arr,long long pages){
        long long students=1;
        long long pageStudent=0;
        
        for(int i=0;i<arr.size();i++){
            if(pageStudent+arr[i]<=pages){
                pageStudent+=arr[i];
            }
            else{
                students++;
                pageStudent=arr[i];
            }
        }
        return students;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();

        long long low=*max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0ll);
        if(k>n) return -1;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(noOfStuds(nums,mid)>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};