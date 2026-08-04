class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
auto minii = min_element(nums.begin(), nums.end());
auto maxii = max_element(nums.begin(), nums.end());

// To access the values, dereference them with '*'
int mini =*minii;
int maxi=*maxii;
sort(nums.begin(),nums.end());
unordered_map<int,int>mpp;
int x=0;
for(auto it:nums){
    mpp[it]=x;
    x++;
}
        vector<int>ans;
        for(int i=mini;i<=maxi;i++){
            // I have to answer here is x present in my array that too faster than o(n)
            // 
            if(mpp.find(i)==mpp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};