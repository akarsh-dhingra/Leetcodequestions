class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.empty()){
            return "";
        }
        stack<char>st;
        for(int i=0;i<num.length();i++){
            while((!st.empty()&&k>0)&&(st.top()-'0')>(num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
            
        }
        // EDGE CASES:
        // AGR STRING HEE EMPTY HAI TOH:
        // agr ab bhi k value non zero hai 
        while(k>0){  
            st.pop();
            k--;
        }
        if(num.size()==k){
            return "";
        }
        if(st.empty()){
            return "0";
        }
        string res="";  // for putting the elements from stack 
        // into the res.
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        while(res.size()!=0 && res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        if(res.empty()){
            return "0";
        }
        return res;
    }
};