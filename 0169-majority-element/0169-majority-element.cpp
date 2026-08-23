class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int val=ceil(n/2);
        int ans=-1;
        for(int i=0;i<n;i++){
            if(mpp[nums[i]]>val) ans=nums[i];
        }
        return ans;
    }
    };