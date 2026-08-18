class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int l=0;
        int r=0;
        if(k==n){
            int ele=INT_MIN;
            for(int x:nums){
                ele=max(ele,x);
            }
            return ele;
        }
        while(r<n){
            if(r-l+1==k){
                for(int i=l;i<=r;i++){
                    mpp[nums[i]]++;
                }
                l++;
            }
            r++;
        }
        int ele=INT_MIN;
        for(auto &it:mpp){
            int elem=it.first;
            int freq=it.second;

            if(freq==1){
                ele=max(ele,elem);
            }
        }
        return ele==INT_MIN?-1:ele;
    }
};