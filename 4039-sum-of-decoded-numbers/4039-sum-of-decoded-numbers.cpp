class Solution {
public:
    long long modpow(long long x,long long y){
        long long MOD=1e9+7;
        long long res=1;
        while(y>0){
            if(y & 1){
                res = res*x % MOD;
            }
            x = x*x %MOD;
            y >>= 1;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        // since y can be a lot larger hence in this
        // particular case we can say that we'll use binary 
        // exponentiation

        int n=nums.size();
        int res=0;
        int MOD=1e9+7;
        for(int i=0;i<n;i++){
            long long x=nums[i];
            long long width=nums[i]%10;
            long long d=nums[i]/10;

            // we'll now make a string 
            string s=to_string(d);

            string start=s.substr(0,width);
            string end=s.substr(width);

            long long xi=stoll(start);
            long long yi=stoll(end);

            long long p=modpow(xi,yi);
            p=p%MOD;
            res=(long long)(res+p)%MOD;
        }
        return res;
    }
};