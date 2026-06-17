class Solution {
public:
    char processStr(string s, long long k) {
        string result="";
        int n=s.size();
        // In order to evaluate the kth char we don't 
        // need the entire string because uski need hee nahi 
        // hume bss kth char chahiye and our job is done 
// Since directly simulating the construction of result is infeasible,
        // Instead of trying to determine which character ends up at position k in the final string. We can try to determine 
        long long len=0;
        for(auto c:s){
            if(c=='*'){
                if(len) len--;
            }
            else if(c=='#'){
                len *=2;
            }
            else if(c=='%'){
                continue;
            }
            else{
                len++;
            }
        }
        if(k>=len) return '.';
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='*'){
            len++; 
            }
            else if(s[i]=='%'){
                k=len-k-1;
            }
            else if(s[i]=='#'){
                if(k>(len-1)/2){
                    k=k-len/2;
                }
                len=(len+1)/2;
            }
            else{
                if(k+1==len) return s[i];
                else len--;
            }

        }
        return '.';
    }
};