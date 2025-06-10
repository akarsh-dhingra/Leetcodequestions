class Solution {
public:
    bool isValid(string s) {
      if(s.size()==1||s.size()==0) return false;
      stack<int>st;

      for(int i=0;i<s.size();i++){
        if(st.empty()){
            if(s[i]==']'||s[i]==')'||s[i]=='}'){
                return false;
            }
            else{
                st.push(s[i]);
            }
        }
      else if((st.top()=='['&&s[i]==']')||(st.top()=='{'&&s[i]=='}')||(st.top()=='('&&s[i]==')')){
            st.pop();
        }
        else st.push(s[i]);
      }
      if(st.empty()) return true;
      else return false;
    }
};