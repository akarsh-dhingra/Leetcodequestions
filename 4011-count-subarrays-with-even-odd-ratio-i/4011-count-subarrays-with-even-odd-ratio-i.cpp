class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        float initRatio =(float) a/b;
        int n=nums.size();
        // int l=0;
        // int r=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            int cntEve=0;
            int cntOdd=0;
            
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) cntEve+=1;
                else cntOdd+=1;
                float ans=(float) cntEve/cntOdd;
                if(initRatio>=ans){
                    cnt++;
                }
            }
        }
       return cnt;
    }   

};