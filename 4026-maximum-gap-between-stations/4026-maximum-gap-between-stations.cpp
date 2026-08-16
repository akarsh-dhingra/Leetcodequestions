class Solution {
public:
    int maximumGap(string skill, string station) {
        // har ak worker ko ak distinct station par rkhna hai !!
        int n=skill.size();
        int m=station.size();

        vector<int>left(n,-1);
        int l=0;
        int r=0;
        while(l<n){
            if(skill[l]==station[r]){
                left[l]=r;
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        vector<int>right(n,-1);
        l=n-1;
        r=m-1;
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
        int ans=0;
        for(int i=1; i<n; i++){
            ans = max(ans, right[i] - left[i-1]);
        }

    return ans;


        // station[j]==skill[i];
        
    }
};