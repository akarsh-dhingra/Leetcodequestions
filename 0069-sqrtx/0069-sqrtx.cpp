class Solution {
public:
    int mySqrt(int x) {
        long long ans=0;
        if(x==0) return 0;
        if(x==1) return 1;

        for(long long i=1;i<x;i++){
                if(i*i<=x){
                    ans=i;
                }
                else break;
        }
        return ans;
    }
};