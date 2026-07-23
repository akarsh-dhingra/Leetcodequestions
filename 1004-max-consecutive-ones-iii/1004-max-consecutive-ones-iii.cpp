class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // maximum no. of consecutive ones is you can flip atmost k 0's
        // nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2

    // maximize consectuvie ones 
        // Ultimately question becomes to find the longest substring with at most k 0's 

        int n=nums.size();
        int maxlen=INT_MIN;

        int l=0;
        int r=0;
        int cnt=0;
        while(r<n){
            if(nums[r]==0) cnt++;
            while(cnt>k){
                if(nums[l]==0) cnt-=1;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        if(maxlen==INT_MIN) return 0;
        return maxlen;
    }
};