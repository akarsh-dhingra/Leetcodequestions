class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int indx1=0;
        int indx2=numbers.length-1;
        int[] ans = new int[2];
        while(indx1<indx2){
            if(numbers[indx1]+numbers[indx2]==target){
                ans[0]=indx1+1;
                ans[1]=indx2+1;
                break;
            }
            if(numbers[indx1]+numbers[indx2]<target){
                indx1++;
            }
            else if(numbers[indx1]+numbers[indx2]>target){
                indx2--;
            }
        }
        return ans;
    }
}