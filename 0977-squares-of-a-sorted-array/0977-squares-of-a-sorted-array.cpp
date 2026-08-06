class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
            int n=nums.size();
            vector<int>ans(n,0);
            int left=0;
            int right=n-1;
            int indx=n-1;
            while(left<=right){
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
                if(leftSquare>rightSquare){
                    ans[indx]=leftSquare;
                    left++;
                }
                else{
                    ans[indx]=rightSquare;
                    right--;
                }
                indx--;
            }
            return ans;
    }
};