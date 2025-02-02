class Solution {
public:
    int divide(int dividend, int divisor) {
       if(dividend==divisor) return 1;
       // Edge case when both are equal.
       bool sign=true;
       // considering a flag for making the sign operationn easy.
       if(dividend>=0&&divisor<0){
        sign=false;
       }
       else if (dividend<0&&divisor>0){
        sign =false;
       }
       long n=labs(dividend);
       long d=labs(divisor);
       long ans=0;
       while(n>=d){
        int cnt=0;
        while(n>=(d<<(cnt+1))){
            cnt++;
        }
        ans+=(1L<<(cnt));
        n-=(d<<(cnt));
       }
     if (ans > INT_MAX) return sign ? INT_MAX : INT_MIN;
    return sign ? ans : -ans;
    }
};