class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
            int n=heights.size();
            stack<int>st;
            int maxArea=0;
            int pse;
            int nse;
            for(int i=0;i<n;i++){
                while(!st.empty()&& heights[st.top()]>heights[i]){
                    int element=st.top();
                    st.pop();
                    nse=i;
                    pse=st.empty()?-1:st.top();
                    maxArea=max(maxArea,(nse-pse-1)*heights[element]);
                }
                st.push(i);
            }

            while(!st.empty()){
                int element=st.top();
                st.pop();
                nse=n;
                pse=st.empty()?-1:st.top();
                maxArea=max(maxArea,(nse-pse-1)*heights[element]);
            }
            return maxArea;
    }
};