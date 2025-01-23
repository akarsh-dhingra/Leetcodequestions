class Solution {
public:
void f(int indx, vector<int>& current,vector<vector<int>>&result,vector<int>& nums){
    if(indx>=nums.size()){
        result.push_back(current);
        return;
    }
    current.push_back(nums[indx]);
    f(indx+1,current,result,nums);

    current.pop_back();
    f(indx+1,current,result,nums);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>current;
        f(0,current,result,nums);
        return result;
    }
};