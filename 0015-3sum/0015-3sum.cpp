class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int l=i+1;
            int r=n-1;
            int rhs=-(nums[i]);
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum==rhs){
                    vector<int>temp={nums[i],nums[l],nums[r]};
                    ans.push_back(temp);
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]){
                        l++;
                    }
                    while(l<r && nums[r]==nums[r+1]){
                        r--;
                    }
                }
                else if(sum<rhs){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
};