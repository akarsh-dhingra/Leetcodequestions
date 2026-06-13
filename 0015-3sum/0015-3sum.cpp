/*

on using an O(n^3) approach we will get ultimately 
all the triplets possible but 
{0,1,-1} and {-1,0,1} as well 

so now these are same but set will not recognise them since
ordering is different

Now optimising to something better near about o(n^2)

Now practcally we are using third loop because we need the sum 
But is it there really need of it ??

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;

            while(j<k){
                long long sum=1LL*(nums[i]+nums[j]+nums[k]);
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
return ans;  
    }
};