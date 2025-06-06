class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>mapp(26,0);
        for(int i=0;i<s.size();i++){
            mapp[s[i]-'a']=i;
        }
        vector<bool>seen(26,false);
        stack<char>st;

        for(int i=0;i<s.size();i++){
            int curr=s[i]-'a';
            if(seen[curr]) continue;
            else{
                while(st.size()>0&&st.top()>s[i]&&i<mapp[st.top()-'a']){
                    seen[st.top()-'a']=false;
                    st.pop();
                }
                st.push(s[i]);
                seen[curr]=true;
            }
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};