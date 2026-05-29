class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // We have to return number of unique elements
        // 'k' after deleting all duplicates
        int l=0;
        int r=1;
        int n=nums.size();
        while(r<n){
            if(nums[l]!=nums[r]){
                l++;
                nums[l]=nums[r];
            }
            r++;

        }
        return l+1;
    }
};