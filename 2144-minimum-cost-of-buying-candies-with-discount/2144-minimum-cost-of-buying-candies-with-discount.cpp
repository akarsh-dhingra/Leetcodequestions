class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // sold 2 get 1 freee
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int sum=0;
        int j=n-1;
        int cnt=0;
        while(j>=0){
            sum+=cost[j];
            cnt++;
            if(cnt%2==0){
                j-=2;
            }
            else j--;
        }
        return sum;
    }
};