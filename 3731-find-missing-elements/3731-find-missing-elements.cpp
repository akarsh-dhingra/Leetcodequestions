class Solution {
public:
    bool findOut(vector<int>&nums,int target){
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
    vector<int> findMissingElements(vector<int>& nums) {
auto minii = min_element(nums.begin(), nums.end());
auto maxii = max_element(nums.begin(), nums.end());

// To access the values, dereference them with '*'
int mini =*minii;
int maxi=*maxii;
sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=mini;i<=maxi;i++){
            // I have to answer here is x present in my array that too faster than o(n)
            // 
            if(!findOut(nums,i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};