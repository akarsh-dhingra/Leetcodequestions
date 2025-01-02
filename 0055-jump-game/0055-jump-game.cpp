class Solution {
public:
    bool canJump(vector<int>& nums) {
      // if the maxindx never touches me means it cannot reach the end.
      int n=nums.size();
      int maxIndx=0;
      for(int i=0;i<n;i++){
        if(i>maxIndx){
            return false;
        }
        maxIndx=max(maxIndx,nums[i]+i);
      }
      return true;
    }
};