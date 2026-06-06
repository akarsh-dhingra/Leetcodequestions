class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         vector<int>ans;
         int n=nums.size();

         for(int i=0;i<n;i++){
            int el=nums[i];
            int freq=0;
            if(ans.size()==0 ||ans[0]!=nums[i]){
            for(int j=0;j<n;j++){
                if(el==nums[j]) freq++;
            }
            if(freq>floor(n/3)){
                ans.push_back(nums[i]);
            }
            }
            if(ans.size()==2 ) break;
         }
        return ans;
    }
};