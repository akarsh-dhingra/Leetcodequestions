class Solution {
public:
string removeDuplicates(string s) {
string ans="";
stack<char>st;
int indx=0;
while(indx<s.length()){
    if(!st.empty()&&st.top()==s[indx]){
        st.pop();
        indx++;
    }
    else {
        st.push(s[indx++]);
    }
}
while(!st.empty()){
    ans+=st.top();
    st.pop();
}
reverse(ans.begin(),ans.end());
return ans;
}
};