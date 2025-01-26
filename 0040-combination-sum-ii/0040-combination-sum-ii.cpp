class Solution {
public:
void combinations(int indx,vector<vector<int>>&result,vector<int>&ds,vector<int>& candidates, int target){
if(target==0){
result.push_back(ds);
return;
}
for(int i=indx;i<candidates.size();i++){
if(i>indx&&candidates[i]==candidates[i-1]) continue;
if(candidates[i]>target) break;
ds.push_back(candidates[i]);
combinations(i+1,result,ds,candidates,target-candidates[i]);
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