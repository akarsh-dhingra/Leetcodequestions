class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size(); 
        if(n==1) return 0;
        int m=station.size(); 
        vector<int>left(n,-1); 
        int l=0;
        int r=0;
        while(l<n && r<m){
            if(skill[l]==station[r]){
                left[l]=r;
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        l=n-1;
        r=m-1;
        vector<int>right(n,-1); 
        while(r>=0 && l>=0){
            if(skill[l]==station[r]){
                right[l]=r;
                l--;
                r--;
            }
            else{
                r--;
            }
        }
        int maxi=0;
        for(int i=1;i<n;i++){
            maxi=max(maxi,right[i]-left[i-1]);
        }
        return maxi;
    }
};