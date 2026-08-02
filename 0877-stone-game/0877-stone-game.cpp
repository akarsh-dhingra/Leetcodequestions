class Solution {
public:
    int solve(int i,int j,vector<int>& piles,vector<vector<int>>&stones){
        if(i>j) return 0;
        if(i==j) return piles[i];
        if(stones[i][j]!=-1) return stones[i][j];
        int take_i=piles[i]+min(solve(i+2,j,piles,stones),solve(i+1,j-1,piles,stones));
        int take_j=piles[j]+min(solve(i,j-2,piles,stones),solve(i+1,j-1,piles,stones));
        return stones[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>stones(n+1,vector<int>(n+1,-1));
        int total_score=accumulate(piles.begin(),piles.end(),0);
        int score1=solve(0,n-1,piles,stones);
        int score2=total_score-score1;
        return score1>score2;
    }
};