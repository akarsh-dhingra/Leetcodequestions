class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
         unordered_map<int,int>mpp;
            mpp[0]=1; // for the case where prefix-k==0
            int cnt=0;
            int prefix=0;

            for(int num:nums){
                    prefix+=num;
                    if(mpp.find(prefix-goal)!=mpp.end()){
                        cnt+=mpp[prefix-goal];
                    }
                    mpp[prefix]++;
            }
            return cnt;
    }
};