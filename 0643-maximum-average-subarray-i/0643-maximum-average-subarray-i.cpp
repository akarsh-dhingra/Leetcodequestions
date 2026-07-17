class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //  find avg of all nums from o to k-1 
        int l=0;
        int r=k-1;
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double MaxSum=sum;
        int n=nums.size();
        for(int i=k;i<n;i++){
            sum+=nums[i]-nums[i-k];
            MaxSum=max(sum,MaxSum);
        }
        return MaxSum/k;

    }
};