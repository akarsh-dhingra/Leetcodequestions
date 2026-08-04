class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
auto minii = min_element(nums.begin(), nums.end());
auto maxii = max_element(nums.begin(), nums.end());

// To access the values, dereference them with '*'
int mini =*minii;
int maxi=*maxii;
        vector<int>ans;
        for(int i=mini;i<=maxi;i++){
            auto it=find(nums.begin(),nums.end(),i);  // o(n)
            if(it==nums.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};