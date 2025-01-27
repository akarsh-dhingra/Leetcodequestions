class Solution {
public:
void f(int indx,vector<vector<int>>&result,vector<int>&curr,vector<int>& nums){
        result.push_back(curr);
    for(int i=indx;i<nums.size();i++){
        if(i!=indx&&nums[i]==nums[i-1])continue;
        curr.push_back(nums[i]);
        f(i+1,result,curr,nums);
        curr.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        vector<int>curr;
        f(0,result,curr,nums);
        return result;
    }
};