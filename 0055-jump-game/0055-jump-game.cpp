class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndx=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxIndx){
                return false;
            }
            maxIndx=max(maxIndx,i+nums[i]);
            if(maxIndx>nums.size()){
                break;
            }
        }
        return true;
    }
};