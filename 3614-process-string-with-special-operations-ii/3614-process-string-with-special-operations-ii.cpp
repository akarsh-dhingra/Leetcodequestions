class Solution {
public:
    char processStr(string s, long long k) {
        long long len=0;

        for(auto ch:s){
            if(ch=='#'){
                len*=2;
            }
            else if(ch=='*'){
                if(len) len--;
            }
            else if (ch=='%'){
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
            else if(s[i]=='#'){
                 len=len/2;
                 k=(k>=len)?k-len:k;
            }
            else if(s[i]=='%'){
                k=len-k-1;
            }
            else {
                len--;
            }

            if(k==len){
                return s[i];
            }
        }
    return s[k];
    }
};