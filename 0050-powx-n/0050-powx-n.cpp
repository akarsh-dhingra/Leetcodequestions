class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
      long exp =n;
      if(n==0) return 1;
      else if (n<0){
        x=1/x;
        exp*=-1;
      }
      double ans=1;
      while(exp>0){
        if(exp%2!=0){
            exp=exp-1;
            ans=ans*x;
        }
        else{
            exp=exp/2;
            x=x*x;
        }
      }
      return ans;
    }
};