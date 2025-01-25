class Solution {
public:
void solution(int indx,vector<vector<int>>&result,vector<int>&ds,int target,vector<int>&candidates){
if(indx==candidates.size()){
    if(target==0){
        result.push_back(ds);
    }
    return;
}
if(candidates[indx]<=target){
ds.push_back(candidates[indx]);
solution(indx,result,ds,target-candidates[indx],candidates);
ds.pop_back();
}
solution(indx+1,result,ds,target,candidates);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>ds;
        int indx=0;
        solution(indx,result,ds,target,candidates);
        return result;
    }
};