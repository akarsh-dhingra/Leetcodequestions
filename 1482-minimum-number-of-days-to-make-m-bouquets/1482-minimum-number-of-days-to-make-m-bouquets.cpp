class Solution {
public:
    bool possiblee(vector<int>& bloomDay,int day, int m, int k){
        int n=bloomDay.size();
        int cnt=0;
        int noOfBoq=0;
    if(m*k> n) return false;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else {
                noOfBoq+=(cnt/k);
                cnt=0;
            }
        }
        noOfBoq+=(cnt/k);
        if(noOfBoq>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long x=m;
        long y=k;
        if(x*y>bloomDay.size()) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());

        while(low<=high){
            int mid=(low+high)/2;
            if(possiblee(bloomDay,mid,m,k)==false){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }
};