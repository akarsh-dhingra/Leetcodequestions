class Solution {
public:
    int waviness(int x){
        int cnt=0;
        vector<int>d;

        while(x>0){
            d.push_back(x%10);
            x/=10;
        }

        if(d.size()<3) return 0;
        
        for(int i=1;i<d.size()-1;i++){
            if((d[i]>d[i+1]&& d[i]>d[i-1])||(d[i]<d[i-1]&&d[i]<d[i+1])){
                cnt++;
            }
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int cnt=0;
        for(int i=num1;i<=num2;i++){
            cnt+=waviness(i);
        }
        return cnt;
    }
};