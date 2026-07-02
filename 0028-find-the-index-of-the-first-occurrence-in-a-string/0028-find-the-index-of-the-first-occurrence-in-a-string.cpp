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
    vector<int>LPsS(string needle){
        int m=needle.size();
        vector<int>LPS(m+1,0);
        LPS[0]=0;
        int i=1;
        int length=0;
        while(i<m){
            if(needle[i]==needle[length]){
                length++;
                LPS[i]=length;
                i++;
            }
            else{
                if(length!=0){
                    length=LPS[length-1];
                }
                else{
                    LPS[i]=0;
                    i++;
                }
            }
        }
        return LPS;
    }
    int strStr(string haystack, string needle) {
        ll n=haystack.size();
        ll m=needle.size();
    vector<int>LPS=LPsS(needle);
        if(n<m) return -1;
        int i=0;
        int j=0;

        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==m){
                j=LPS[j-1];
               return i-m; 
            }
            else if(haystack[i]!=needle[j]){
                if(j!=0) j=LPS[j-1];
                else i++;
            }
        }
        return -1;
    }
};