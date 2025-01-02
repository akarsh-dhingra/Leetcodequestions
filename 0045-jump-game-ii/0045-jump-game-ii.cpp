class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return 0;
        }
        int currentend=0;
        int maxreach=0;
        int jumps=0;
        for(int i=0;i<n;i++){
            maxreach=max(maxreach,i+nums[i]);
            if(currentend==i){
                jumps++;
                currentend=maxreach;
                if(currentend>=n-1){
                    break;
                }
            }
        }
        return jumps;
    }
};