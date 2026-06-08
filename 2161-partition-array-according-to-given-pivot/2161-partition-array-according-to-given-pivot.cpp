class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int countLess=0;
        int equal=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot) countLess++;
            if(nums[i]==pivot) equal++;
        }
        
        int lessI=0;
        int equalI=countLess;
        int greaterI=countLess+equal;
        vector<int>ans(nums.size(),0);
       for(int num:nums){
        if(num<pivot) {
            ans[lessI]=num; 
            lessI++;
        }
        else if(num==pivot){
            ans[equalI]=num; 
            equalI++;
        }
        else {
            ans[greaterI]=num; 
            greaterI++;
            }
       }
        return ans;
    }
};