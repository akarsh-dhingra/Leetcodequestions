class Solution {
public:
void solve(vector<vector<int>>&ans,vector<int>&temp,vector<int>& nums,int indx,int n){
    // Agr mai ak baar ak element ko exclude kr chuka hu toh aage ka saare same elements 
    // kabhi incluce nahiu ho skte !!!
    if(indx==n){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[indx]);
    solve(ans,temp,nums,indx+1,n);
    temp.pop_back();
    while(indx+1<n && nums[indx]==nums[indx+1]) indx++;
    solve(ans,temp,nums,indx+1,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        int indx=0;
        int n=nums.size();
        solve(ans,temp,nums,0,n);
        return ans;
    }
};