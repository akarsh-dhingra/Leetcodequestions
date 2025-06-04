class Solution {
public:
    string removeDuplicates(string s) {
        // step 1:choosing any adjacent and two equal letters indx and indx+1
        // step 2: delete those and use this string to repeat step 1
        // step 3: return
        // edge case if no adjacent duplicates
        // stack sa 
        // string ko built krte hai from scratch -> Pattern
        // find 
        int len=s.length();
        int indx=0;
        stack<int>st;
        string res="";
        while(indx<len){
            if(st.size()>0&&st.top()==s[indx]){
                st.pop();
            }
            else{
                st.push(s[indx]);
            } 
            indx++;
        }
        while(!st.empty()){
          res.push_back(st.top());
          st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};