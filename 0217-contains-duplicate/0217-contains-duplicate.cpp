class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]>=2){
                return true;
            }
        }
        return false;
    }
};