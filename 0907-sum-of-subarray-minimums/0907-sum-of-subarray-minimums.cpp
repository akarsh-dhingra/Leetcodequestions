class Solution {
public:
#define MOD 1000000007
    vector<int>nsse(vector<int>& arr){
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int>psee(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n);
        
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse=nsse(arr);
        vector<int>pse=psee(arr);
        int n=arr.size();
        long long sum=0;

        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            sum=(sum+(right*left*1LL*arr[i])%MOD)%MOD;
        }
        return sum%MOD;
    }
};