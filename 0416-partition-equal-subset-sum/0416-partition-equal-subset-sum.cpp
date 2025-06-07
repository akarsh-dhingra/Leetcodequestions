class Solution {
public:

  bool isSubsetSumrec(vector<int>& arr,int n,int sum){
    vector<vector<double>>t(n+1,vector<double>(sum+1,false));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j==0)  t[i][j]=true;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j]||t[i-1][j-arr[i-1]];
            }
            else t[i][j]=t[i-1][j];
        }

    }
    return t[n][sum];
  }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        else{
            return isSubsetSumrec(nums,n,sum/2);
        }
    }
};