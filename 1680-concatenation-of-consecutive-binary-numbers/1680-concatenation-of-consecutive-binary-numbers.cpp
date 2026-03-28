class Solution {
public:
long long M=1e9+7;
    int concatenatedBinary(int n) {
        long long result=0;
        int digits=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0)digits++;
            result=((result<<digits)%M+i)%M;
        }
        return result;
    }
};