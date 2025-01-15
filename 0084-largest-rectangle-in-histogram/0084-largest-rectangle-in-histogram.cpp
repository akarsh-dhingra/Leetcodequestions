class Solution {
public:
vector<int> prevSmallerElement(vector<int> &arr, int n){
stack<int>st;
st.push(-1);
vector<int>ans(n);
for (int i = 0; i<=n-1; i++){
int curr_ele=arr[i];
// answer find karo and isko store karo 
while(st.top()!=-1&&arr[st.top()]>=curr_ele){
st.pop();
}
    ans[i]=st.top();
    st.push(i);// yeh kisi aur ka toh smaleest element ho skta hai
}
    return ans;
}
vector<int> nextSmallerElement(vector<int> &arr, int n){
stack<int>st;
st.push(-1);
vector<int>ans(n);
for (int i = n-1; i>=0; i--){
int curr_ele=arr[i];
// answer find karo and isko store karo 
while(st.top()!=-1&&arr[st.top()]>=curr_ele){
    st.pop();
}
 ans[i] = (st.top() == -1 ? n : st.top()); // store the smallest ekemetn
st.push(i);  // yeh kisi aur ka toh smaleest element ho skta hai
}
return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if (n==0) return 0;
if(n==1) return heights[0];
        vector<int>next= nextSmallerElement(heights,n);
        vector<int>prev= prevSmallerElement(heights,n);
        int maxi=-1;
        for(int i=0;i<n;i++){
            int length=heights[i];
            int width=next[i]-prev[i]-1;
            int area=length*width;
            maxi=max(area,maxi);
        }
        return maxi;
    //    //// w=next-prev-1;
    //     for(int i=1;i<n;i++){
    //         width=heights[i];
    //         if(width<=heights[i+1]){
    //             length+=1;
    //         }
    //         else if(width)
    //     }
    }
};