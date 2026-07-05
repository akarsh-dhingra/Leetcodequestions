class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    // nge ka code likhte hai for nums2 
    // nums1 ka liye fir iterate krkr nikal lenge
    int n=nums2.size();

    stack<int>st;
    map<int,int>nge;
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&& st.top()<=nums2[i]){
            st.pop();
        }
        nge[nums2[i]]=st.empty()?-1:st.top();
        st.push(nums2[i]);
    }

    vector<int>ans;
    for(int i=0;i<nums1.size();i++){
        if(nge.find(nums1[i])!=nge.end()){
            ans.push_back(nge[nums1[i]]);
        }
    }
    return ans;

    }
};