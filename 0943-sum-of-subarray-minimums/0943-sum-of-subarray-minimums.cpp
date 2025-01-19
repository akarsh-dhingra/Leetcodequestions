class Solution {
public:
vector<int>nextsmallerelement(vector<int>& arr){
    stack<int>st;
    // st.push(-1);
        int n=arr.size();
    vector<int>ans(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&& arr[st.top()]>arr[i]){
            st.pop();
        }
        ans[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return ans;
}
vector<int>prevsmallerele(vector<int>& arr){
    stack<int>st;
    int n=arr.size();
    vector<int>ans(n,n);
    for(int i=0;i<n;i++){
        while(!st.empty()&&arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return ans;
}
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int modulo=(int)1e9+7;
        vector<int>leftside=prevsmallerele(arr);
        vector<int>rightside=nextsmallerelement(arr);
        int total=0;
        for(int i=0;i<n;i++){
            int left=i-leftside[i];
            int right=rightside[i]-i;
            total=(total+(long long )left*right*arr[i]%modulo)%modulo;
        }
        return total;
    }
};