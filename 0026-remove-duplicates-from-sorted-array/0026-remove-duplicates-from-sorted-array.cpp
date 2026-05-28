class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    //   Let's create a temp of size n=nums.size()
    //   Now I"ll keep pushing all the unique
    //   values inside the nums array
    int i=0;
    int j=1;
    while(j<nums.size()){
        if(nums[i]!=nums[j]){
            i++;
            nums[i]=nums[j];
        }
        j++;
    }
    return i+1;
    }
};