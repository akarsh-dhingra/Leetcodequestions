class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int origin=n;
        while(n!=0){
            int temp=n%10;
            sum+=temp;
            prod*=temp;
            n/=10;
        }
        return origin%(sum+prod)==0;
    }
};