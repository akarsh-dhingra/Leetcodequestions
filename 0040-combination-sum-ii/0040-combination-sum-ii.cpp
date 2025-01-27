class Solution {
public:
void combinations(int indx,vector<vector<int>>&result,vector<int>&ds,vector<int>&arr, int target){
if(target==0){
    result.push_back(ds);
    return;
}
for(int i=indx;i<arr.size();i++){
    if(i>indx&&arr[i]==arr[i-1]) continue;
    if(arr[i]>target) break;
    ds.push_back(arr[i]);
    combinations(i+1,result,ds,arr,target-arr[i]);
    ds.pop_back();
}
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>ds;
        combinations(0,result,ds,candidates,target);
        return result;
    }
};