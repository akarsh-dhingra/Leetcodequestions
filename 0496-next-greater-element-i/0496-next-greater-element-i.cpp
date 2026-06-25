class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>ngemap;
        int n=nums2.size();
        vector<int>ans;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                ngemap[nums2[i]]=-1;
            }
            else{
                ngemap[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }

        for(auto it:nums1){
            ans.push_back(ngemap[it]);
        }

      return ans;
    }
};