/*
lengths of costs is n --->.  
*/
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        int mx=*max_element(costs.begin(),costs.end());

        vector<int>freq(mx+1,0);
        for(int x:costs){
            freq[x]++;
        }
        int k=0;
        for(int i=0;i<=mx;i++){
            while(freq[i]--){
                costs[k]=i;
                k++;
            }
        }
        
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