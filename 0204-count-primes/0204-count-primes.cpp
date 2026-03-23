class Solution {
public:
    bool isprime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        if(n==0||n==1) return 0;
        vector<bool>isPrime(n+1,true);
        isPrime[0]=false;
        isPrime[1]=false;

        for(int i=2;i<=sqrt(n);i++ ){
            if(isprime(i)){
                for(int j=2;i*j<=n;j++){
                    isPrime[i*j]=false;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                cnt++;
            }
        }
        return cnt;
    }
};