class Solution {
public:
    int sumofdivision(vector<int>& nums, int val){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+ceil((double)(nums[i])/(double)(val));
        }
        return sum;
    }
    int maxel(vector<int>& nums){
        int n=nums.size();
        int max=INT_MIN;
        for(int i=0;i<n;i++){
             if(nums[i]>max){
                max=nums[i];
             }
        }
        return max;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=maxel(nums);
        while(low<=high){
            int mid= low+(high-low)/2;
            if(sumofdivision(nums,mid)<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};