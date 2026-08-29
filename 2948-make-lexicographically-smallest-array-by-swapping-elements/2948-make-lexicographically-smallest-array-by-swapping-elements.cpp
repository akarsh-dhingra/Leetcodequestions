class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // o(nlogn)
        // o(n)
        // long long 1,5,3,9,8
        
        vector<pair<int,int>>arr;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        // Reason why I am sorting is that so that I can find groups in which my condition is getting satisfied or you can say components of graphs
        sort(arr.begin(),arr.end());

        int i=0;  // this is my starting indx of group which will be used to find the 
        // start of any comp
        vector<int>ans(n,0);
        while(i<n){
            int j=i+1;

            while(j<n && arr[j].first-arr[j-1].first<=limit){
                j++;
            }   

            vector<int>indices;
            for(int k=i;k<j;k++){
                indices.push_back(arr[k].second);
            }
            sort(indices.begin(),indices.end());

            for(int k=0;k<indices.size();k++){
                ans[indices[k]]=arr[i+k].first;
            }
            i=j;
        }
        return ans; 
    }
};