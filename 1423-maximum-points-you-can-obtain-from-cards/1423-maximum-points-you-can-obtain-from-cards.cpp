class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=0;
        // calculate lsum
        // calculate rsum 
        // calucate max sum
        int lSum=0;
        int maxSum=0;
        int rSum=0;
        for(int i=0;i<k;i++) lSum+=cardPoints[i];
        maxSum=lSum;
        int rIndx=n-1;
        for(int i=k-1;i>=0;i--){
            lSum-=cardPoints[i];
            rSum+=cardPoints[rIndx];
            maxSum=max(maxSum,lSum+rSum);
            rIndx--;
        }
        return maxSum;
    }
};