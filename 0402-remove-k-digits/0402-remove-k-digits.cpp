class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        if(k==num.size()) return "0";
        for(auto it:num){
            int x=it-'0';
            while(!st.empty()&&st.top()>x&&k>0){
                k--;
                st.pop();
            }
            st.push(x);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=(st.top()+'0');
            st.pop();
        }
       
        reverse(ans.begin(),ans.end());

        int i=0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        if(i==ans.size()) return "0";
        return ans.substr(i);
    }
};