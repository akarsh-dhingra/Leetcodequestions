class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string res="";
        int length_a=a.length();
        int length_b=b.length();

        int n=ceil(length_b/length_a);
        int cnt=n; // cnt ka intn ka hai ki at least cnt times toh string repeeat hogi hee for getting the desired string example 2 of tst case
        while(cnt--){
            res=res+a;
        }
        if(res.find(b)!=string::npos){
            return n;
        }
        res+=a;
        if(res.find(b)!=string::npos){
            return n+1;
        }
        res+=a;
        if(res.find(b)!=string::npos){
            return n+2;
        }

        return -1;
        // if all characters are different then return false;
    }
};