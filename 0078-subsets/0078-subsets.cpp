class Solution {
public:
void f(int indx,vector<int>& nums,vector<int>&ans,vector<vector<int>>&result){
    if(indx==nums.size()){
        result.push_back(ans);
        return;
    }
    ans.push_back(nums[indx]);
    f(indx+1,nums,ans,result);
    ans.pop_back();
    f(indx+1,nums,ans,result);
}
    vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>>result;
            vector<int>ans;
            f(0,nums,ans,result);
            return result;
    }
};