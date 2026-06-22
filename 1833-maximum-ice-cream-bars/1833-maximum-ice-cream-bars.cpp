/*
lengths of costs is n --->.  
*/
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        sort(costs.begin(),costs.end());
        int cnt=0;
        int i=0;
        while(coins!=0&&i<n){
         if(costs[i]>coins){
            break;
         }   
         coins-=costs[i];
            i++;
            cnt++;
        }
        return cnt;
    }
};