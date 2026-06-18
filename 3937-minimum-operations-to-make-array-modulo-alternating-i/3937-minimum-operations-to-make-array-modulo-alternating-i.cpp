class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=INT_MAX;
        int n=nums.size();

        for(int evenRem=0;evenRem<k;evenRem++){

            for(int oddRem=0;oddRem<k;oddRem++){

                if(evenRem==oddRem) continue;
                int cost=0;

                for(int i=0;i<n;i++){
                    int target=(i%2)?evenRem:oddRem;
                    int curr= nums[i]%k;
                    int fwdDist=(target-curr+k)%k;
                    int backDist=(curr-target+k)%k;
                    cost+=min(fwdDist,backDist);
                }
            ans=min(ans,cost);
            }

        }        

        return ans;
    }
};