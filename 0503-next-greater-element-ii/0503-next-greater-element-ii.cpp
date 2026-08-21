class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>nge(n,-1);
        for(int i=n-1;i>=0;i--){
            int ele=nums[i];
            for(int j=1;j<=n;j++){
                int nextEle=nums[(i+j)%n];
                if(nextEle>ele){
                    nge[i]=nextEle;
                    break;
                }
            }
        }
        return nge;
    }
};