class Solution {
public:
    bool possible(vector<int>& bloomDay,int day, int m, int k){
        int cnt=0;
        int noOfbouquets=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                cnt++;
                if(cnt==k){
                    noOfbouquets++;
                    cnt=0;
                }
                }
                else {
                    cnt=0;
                }
            }
            return noOfbouquets>=m;
        }
    int minele(vector<int>& bloomDay){
        int min=INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
                if(min>=bloomDay[i]){
                    min=bloomDay[i];
                }
        }
        return min;
    }
       int maxele(vector<int>& bloomDay){
        int max=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
                if(max<=bloomDay[i]){
                    max=bloomDay[i];
                }
        }
        return max;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=minele(bloomDay);
        int high=maxele(bloomDay);
        long long val= k*1ll*m*1ll;
        if(val>bloomDay.size()) return -1;
        while(low<=high){
            int mid= low+ (high-low)/2;
            if(possible(bloomDay,mid,m,k)==false){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};