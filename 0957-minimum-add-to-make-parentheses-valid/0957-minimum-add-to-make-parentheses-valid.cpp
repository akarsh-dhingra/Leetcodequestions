class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size()==1) return 1;
        int ans=0;
        int open=0;
        for(char c:s ){
            if(c=='('){
                open++;
            }
            else{
                if(open!=0) open--;
                else ans+=1;
            }
        }
        return ans+open;
    }
};