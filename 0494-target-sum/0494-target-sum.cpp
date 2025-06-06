class Solution {
public:
  int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
       vector<vector<int>> t(n + 1, vector<int>(target + 1,0));
        
       for(int i=0;i<n+1;i++){
            for(int j=0;j<target+1;j++){
               if(i==0) t[i][j]=0;
               if(j==0) t[i][j]=1;
            }
        }
        for(int i=1;i<n+1;i++){
        for (int j = 0; j<target+1; j++) {
           if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
                }
                else t[i][j]=t[i-1][j];
            }
        }
        return t[n][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    
    if ((sum + target) % 2 != 0) return 0;  // No valid partition

    int s1 = (sum + target) / 2;
    if(s1<0) return 0;
    return perfectSum(nums, s1);
    }
};