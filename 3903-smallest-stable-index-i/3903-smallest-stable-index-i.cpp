class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int maxi=INT_MIN;
        int miniIndx=100;
        // One approach that you can use 
        // is preProcessing that you preprocess all the mini Pehle sa hee till 
        // a specific index 
        vector<int>miniFromIndx(n,1e9);
        miniFromIndx[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            miniFromIndx[i]=min(nums[i],miniFromIndx[i+1]);
        } 
        while(l<n){
            maxi=max(nums[l],maxi);
            int mini=miniFromIndx[l];
            if(maxi-mini<=k){
                miniIndx=min(miniIndx,l);
            }
            l++;
        }
    return miniIndx==100?-1:miniIndx;
    }
};