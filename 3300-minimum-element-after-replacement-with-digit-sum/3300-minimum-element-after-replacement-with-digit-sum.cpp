class Solution {
public:
    int calculateSum(int x){
        int sum=0;
        while(x!=0){
            sum+=x%10;
            x=x/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int miniSum=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=calculateSum(nums[i]);
            miniSum=min(sum,miniSum);
        }
        return miniSum;
    }
};