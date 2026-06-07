class Solution {
public: 
    int longestConsecutive(vector<int>& nums) {
      int n=nums.size();
      if(nums.size()==0) return 0;
      int longest=1;
      unordered_set<int>st;
      for(int i=0;i<n;i++){
        st.insert(nums[i]);
      }

      for(auto it:st){
        if(st.find(it-1)==st.end()){
            int currEle=it;
            int cnt=1;
            // currele=1;
            while(st.find(currEle+1)!=st.end()){
                cnt++;
                currEle++;
            }
            longest=max(longest,cnt);
        }
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