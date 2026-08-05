class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        int minSum=INT_MAX;
        int minDiff=INT_MAX;
        for(int i=0;i<n-2;i++){

            int l=i+1;
            int r=n-1;
            int val=nums[i];
            
            
            while(l<r){
                int sum=val+nums[l]+nums[r];
                int diff=abs(sum-target);
                if(sum==target){
                    return sum;
                }
                else if(sum>target){
                    if(diff<minDiff){
                    minDiff=min(minDiff,diff);
                    minSum=sum;
                    }
                    r--;
                }
                else{
                    if(diff<minDiff){
                    minDiff=diff;
                    minSum=sum;
                    }
                    l++;
                }
            }
        }
        return minSum;
    }
};