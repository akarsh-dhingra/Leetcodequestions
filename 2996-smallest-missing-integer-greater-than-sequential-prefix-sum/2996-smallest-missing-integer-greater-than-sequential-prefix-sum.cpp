class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sumInit=nums[0];
        int n=nums.size();
        int maxSum=INT_MIN;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1) sumInit+=nums[i];
            else {
                maxSum=max(maxSum,sumInit);
                sumInit=0;
                break;
            }
        }
        int num=maxSum==INT_MIN?sumInit:maxSum;
        // maxSum
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(num==nums[i])num++;
        }
        return num;
    }
};