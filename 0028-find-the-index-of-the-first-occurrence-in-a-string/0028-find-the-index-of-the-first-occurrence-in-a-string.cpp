#define ll long long int
#define MOD 1000000007
class Solution {
    // Radix is the base of the number system in 
    // our case it is 26
public:
    ll hashValue(string string,ll radix,ll m){
        ll ans=0,factor=1;
        for(ll i=m-1;i>=0;i--){
            ans+=((string[i]-'a')*factor)%MOD;
            factor=(factor*radix)%MOD;
        }
        return ans%MOD;
    }
    int strStr(string haystack, string needle) {
        ll n=haystack.size();
        ll m=needle.size();

        if(n<m) return -1;

        ll radix=26;
        ll MAX_WEIGHT=1;

        for(ll i=1;i<=m;i++){
            MAX_WEIGHT=(MAX_WEIGHT*radix)%MOD;
            // (26)^m
        }
        
        ll hashNeedle=hashValue(needle,radix,m);
        ll hashhay=0;
        for(ll i=0;i<=n-m;i++){
            if(i==0){
                hashhay=hashValue(haystack,radix,m);
            }
            else{
        hashhay=((hashhay*radix)%MOD-((haystack[i-1]-'a')*MAX_WEIGHT)%MOD+(haystack[i+m-1]-'a')+MOD)%MOD;
            }
            if(hashNeedle==hashhay){
                for(ll j=0;j<m;j++){
                    if(needle[j]!=haystack[j+i]) break;
                    if(j==m-1) return i;
                }
            }
        }
        return -1;
    }
};