class Solution {
public: 
    int longestConsecutive(vector<int>& nums) {
      int n=nums.size();
      int maxiCnt=INT_MIN;
      if(nums.size()==0) return 0;
      int longest=1;
      int lastSmaller=INT_MIN;
      int cnt=0;
      sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){

            if(nums[i]-1==lastSmaller){
                cnt+=1;
                lastSmaller=nums[i];
            }
            else if(lastSmaller!=nums[i]){
                cnt=1;
                lastSmaller=nums[i];
            }
            longest=max(longest,cnt);
        }
      return longest;
    }
};


    // for(int i=0;i<n;i++){
    //     if(lastSmaller==INT_MIN){
    //         cntCurr+=1;
    //         lastSmaller=nums[i];
    //     }
    //     if(lastSmaller+1!=nums[i]){
    //         lastSmaller=nums[i];
    //         cntCurr=1;
    //     }
    //     else if(lastSmaller+1==nums[i]){
    //         lastSmaller=nums[i];
    //         cntCurr+=1;
    //     }
    //   }