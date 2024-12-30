class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivecoins=0;
        int tencoins=0;
        int twentycoins=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                fivecoins+=1;
            }
            else if(bills[i]==10){
                tencoins+=1;
                fivecoins-=1;
                if(fivecoins<0){
                    return false;
                }
            }
            else{
                twentycoins+=1;
                if(fivecoins>0&&tencoins>0){
                fivecoins-=1;
                tencoins-=1;   
                }
                else if(fivecoins>=3){
                    fivecoins-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};