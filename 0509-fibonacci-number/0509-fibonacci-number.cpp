class Solution {
public:
    int solveUsingRec(int n){
        if (n==0 || n==1) return n;
        return solveUsingRec(n-1)+solveUsingRec(n-2);
    }

    int fib(int n) {
    return solveUsingRec(n); 
    }
};