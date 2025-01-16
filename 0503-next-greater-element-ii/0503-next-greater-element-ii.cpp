class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>nge(n,-1);  // if not declared will give segmentation fault.
        if(n==1){
            return nge;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=i+n-1;j++){  // circular array: we have to compare every element with all the element  in the array for that we need to make sure that window size is ==N all the time.
            int indx=j%n;
            if(nums[indx]>nums[i]){
                nge[i]=nums[indx];
                break;
            }
            else{
                nge[i]=-1;
            }
            }
        }
        return nge;
    }
};