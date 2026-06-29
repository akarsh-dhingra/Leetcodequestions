class Solution {
    public:
    void createMapping(map<int,string>&mpp){
        mpp[1]="I";
        mpp[4]="IV";
        mpp[9]="IX";
        mpp[5]="V";
        mpp[10]="X";
        mpp[40]="XL";
        mpp[90]="XC";
        mpp[50]="L";
        mpp[100]="C";
        mpp[400]="CD";
        mpp[500]="D";
        mpp[900]="CM";
        mpp[1000]="M";
    }
    string intToRoman(int num) {
        map<int,string>mpp;
        createMapping(mpp);
        string ans="";
        
        for(auto it=mpp.rbegin();it!=mpp.rend();it++){
            while(num>=it->first){
                num-=it->first;
                ans+=it->second;
            }
        }
    return ans;
    }
};