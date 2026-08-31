class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=min_element(nums.begin(),nums.end())-begin(nums);
        int maxi=max_element(nums.begin(),nums.end())-begin(nums);

        int left=min(mini,maxi);
        int right=max(mini,maxi);


        return min({left+1+n-right,right+1,n-left});
    }
};