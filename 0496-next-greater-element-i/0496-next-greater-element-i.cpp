class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>ngemap;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums2[i]){
                st.pop(); // I am not finding any next greaeter element I start popping outapplicable for less and equal cases 
            }
            if(st.empty()){
                ngemap[nums2[i]]=-1; // if initially stack is empty from the back push -1l
            }
            else{
                ngemap[nums2[i]]=st.top(); // 
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(auto it:nums1){
            ans.push_back(ngemap[it]);
        }
        return ans;
    }
};