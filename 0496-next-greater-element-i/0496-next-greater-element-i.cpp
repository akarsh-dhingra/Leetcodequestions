class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n;i++){
            int pos=-1; // find the position of the element of nums in nums2
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    pos=j;
                    break;
                }
            }
        int Nge=-1;
        if(pos!=-1){
        for(int k=pos+1;k<m;k++){
            if(nums2[k]>nums2[pos]){
                Nge=nums2[k];
                break;
            }
        }
        }
        ans.push_back(Nge);
        }
return ans;
    }
};