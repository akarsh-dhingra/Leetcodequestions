class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();

        int i=n-1;
        int j=m-1;
        int carry=0;
        string res="";
        while(i>=0 || j>=0 || carry!=0 ){
            int d1=(i>=0)?(a[i]-'0'):0;
            int d2=(j>=0)?(b[j]-'0'):0;
            
            int sum=d1+d2+carry;
            carry=(sum>=2)?1:0;
            res+=to_string(sum%2);
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};