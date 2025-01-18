class Solution {
public:
vector<int> nextsmallerelement(vector<int>& arr){
    stack<int>st;
    int n=arr.size();
    vector<int> ans(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&arr[st.top()]>arr[i]){
        // Update with the next smaller index
        st.pop();
        }
        ans[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return ans;
}
vector<int> prevSmallerequ(vector<int> &a){
    stack<int> st;
    int n = a.size();
    vector<int> ans(n, -1);  // Initialize with `-1` (no smaller element to the left)

    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();  // Update with the previous smaller index 
        st.push(i);
    }
    return ans;
}

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        // int sum=0;
        int modulo=(int)1e9+7;
        // for(int i=0;i<n;i++){
        //     int small=arr[i];
        //     for(int j=i;j<n;j++){
        //         small=min(small,arr[j]);
        //         sum=(sum+small)%modulo;
        //     }
        // }
        vector<int>nse=nextsmallerelement(arr);
        vector<int>pse=prevSmallerequ(arr);
        long long total=0;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
         
        total = (total + (long long)left * right * arr[i] % modulo) % modulo;
        }
        return total;
    }
};