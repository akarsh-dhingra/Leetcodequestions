class Solution {
public:
    string removeDuplicates(string s, int k) {
        // string s
        // har indx sa k ka loop chla dunga 

        int indx=0;
        int len=s.length();
        stack<pair<char,int>>st;
        // count badhaunga only if its equal to prev.
        int n=s.length();
        string res;
        for(char ch:s){
            if(!st.empty()&&ch==st.top().first){
                st.top().second++; // freq count
            }
            else{
                st.push({ch,1});
            }
            
            if(st.top().second==k){
                st.pop();
            }
        }
        while(!st.empty()){ //recovering remaining string from stack
            res.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
        }
};