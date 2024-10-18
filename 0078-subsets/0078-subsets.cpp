class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int subs=1<<n;
        vector<vector<int>> result;
    // looping over all subsets from 0 to 2^n - 1 
    for (int subset_mask=0;subset_mask<=subs-1;subset_mask++){
           vector <int> subset;
           for(int i=0;i<n;i++){
                if (subset_mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
           }
           result.push_back(subset);
    }
    return result;
    }
};