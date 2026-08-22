class Solution {
public:
    int findSum(int n){
        int sum=0;
        while(n!=0){
            int temp=n%10;
            sum+=temp;
            n/=10;
        }
        return sum;
    }
    int findProd(int n){
        int prod=1;
        while(n!=0){
            int temp=n%10;
            prod*=temp;
            n/=10;
        }
        return prod;
    }
    bool checkDivisibility(int n) {
        int sum=findSum(n);
        int prod=findProd(n);
        int x=sum+prod;
        if(n%x==0) return true;
        else return false;
    }
};