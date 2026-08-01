class Solution {
public:
    int solve(int i,int j,vector<int>& nums){
        if(i>j){
            return 0;
        }
        if(i==j) return nums[i];
        long long takei=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        long long takej=nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));
        return max(takei,takej);
    }
    bool predictTheWinner(vector<int>& nums) {
        // 1,5,2
        int n=nums.size();
        int total_score=accumulate(nums.begin(),nums.end(),0);
        int player1_score=solve(0,n-1,nums);
        int player2_score=total_score-player1_score;
        return player1_score>=player2_score;
    }
};