class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        // Solve without finding mini and maxi ??
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        int first=-1;
        int second=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                first=i;
            }
            if(nums[i]==mini){
                second=i;
            }
        }
        int ans1=0;
        if(second>first){
            ans1+=(n-second);
            ans1+=(first+1);
        }
        else{
            ans1+=(second+1);
            ans1+=(n-first);
        }
        int ans2=0;
        if(second>=first) ans2+=(second+1);
        else ans2+=(first+1);
        int ans3=0;
        if(second>=first) ans3+=(n-first);
        else ans3+=(n-second);

        return min(ans1,min(ans2,ans3));
    }
};