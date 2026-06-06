class Solution {
public:
    int cnt=0;
    void countPairs(int low,int mid,int high,vector<int>&nums){
        int right=mid+1;

        for(int i=low;i<=mid;i++){
            while(right<=high && (long long)nums[i]>2LL*nums[right]){
                right++;
            }
            cnt+=(right-(mid+1));
        }
    }
    void merge(int low,int mid,int high,vector<int>&nums){
        vector<int>temp;
        int left=low;
        int right=mid+1;
        
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    void mergeSort(int low,int high,vector<int>&nums){
        if(low>=high) return;
        int mid=(low+high)/2;
        mergeSort(low,mid,nums);
        mergeSort(mid+1,high,nums);
        countPairs(low,mid,high,nums);
        merge(low,mid,high,nums);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        return cnt;
    }
};