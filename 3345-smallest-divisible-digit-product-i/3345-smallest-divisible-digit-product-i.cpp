class Solution {
public:
    int calculateProd(int n){
        int ans=1;
        while(n!=0){
            int temp=n%10;
            ans*=temp;
            n=n/10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        while(1){
            if(calculateProd(n)%t==0){
                return n;
            }
            n++;
        }
    }
};