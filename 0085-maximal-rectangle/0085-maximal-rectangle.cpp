class Solution {
public:
    int largestHist(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        int maxArea=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&& arr[st.top()]>=arr[i]){
                int element=arr[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxArea=max(maxArea,element*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int curr=arr[st.top()];
            st.pop();
            int nse=n;
            int pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,curr*(nse-pse-1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>prefixSum(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
               if(matrix[i][j]=='0'){
                prefixSum[i][j]=0;
               }
               else{
                if(i==0)prefixSum[i][j]=1;
                else prefixSum[i][j]=prefixSum[i-1][j]+1;
               }
            }
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,largestHist(prefixSum[i]));
        }
        return maxArea;
    }
};